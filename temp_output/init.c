
#include <termina.h>

#include "app.h"

#include "resources/tmchannel/queue_u8.h"

void __termina_app__init_globals() {
    
    for (size_t __i0 = 0; __i0 < queue_max_noe; __i0 = __i0 + 1) {
        TMQueue.elements[__i0] = 0;
    }
    TMQueue.head_index = 0;
    TMQueue.num_elements = 0;

    return;

}
