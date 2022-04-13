#include <stdio.h>
#include "factory_config.h"
#include "prod_data.h"

int main() {
    printf("Hello factory!\n");
    printf("Factory version %d.%d\n", FACTORY_VERSION_MAJOR, FACTORY_VERSION_MINOR);
 
    int val = create_data();
    printf("Factory created %d\n", val);
}