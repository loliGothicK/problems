#include "singleton.hpp"

namespace Interface {
    namespace{
        static void Finalizer(){
            Singleton::singletonFinalizer::finalize();
        }
        
        template < typename T >
        class Z {
        public:
        
            static T& get_instance(){
                return Singleton::singleton<T>::get_instance();
            }

            static short Calculate(short const& l, short const& r){
                return T::Calculate(l, r) ;
            }
    
            static auto get_interface()->decltype(&T::Calculate){
                return &T::Calculate ;
            }
        };
    }
}