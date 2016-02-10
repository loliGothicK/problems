#include <mutex>
#include <iostream>
namespace Singleton{
    namespace {
        class singletonFinalizer
        {
        public:
            typedef void(*FinalizerFunc)();

            static void addFinalizer(FinalizerFunc func);
            static void finalize();
        };

        template <typename T>
        class singleton final
        {
        public:
            static T& get_instance()
            {
                std::call_once(initFlag, create);
                return *instance;
            }

        private:
            static void create() {
                instance = new T;
                singletonFinalizer::addFinalizer(&singleton<T>::destroy);
            }

            static void destroy() {
                delete instance;
                instance = nullptr;
            }

            static std::once_flag initFlag;
            static T* instance;
        };

        template <typename T> std::once_flag singleton<T>::initFlag;
        template <typename T> T* singleton<T>::instance = nullptr;
        const  int kMaxFinalizersSize = 256;
        static int gNumFinalizersSize = 0;
        static singletonFinalizer::FinalizerFunc gFinalizers[kMaxFinalizersSize];

        void singletonFinalizer::addFinalizer(FinalizerFunc func) {
            gFinalizers[gNumFinalizersSize++] = func;
        }

        void singletonFinalizer::finalize() {
            for (int i = gNumFinalizersSize - 1; i >= 0; --i) {
                (*gFinalizers[i])();
        #ifdef DEBUG_MODE
                std::cout << "Destroyed" << std::endl;
        #endif
            }
            gNumFinalizersSize = 0;
        }
    }
}