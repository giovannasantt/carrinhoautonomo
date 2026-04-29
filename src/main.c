#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>

#define INPUT_PORT  "GPIO_4"   // Porta E = GPIO_4 no seu .dts
#define INPUT_PIN   20         // PTE20
#define INPUT_PIN2  21

void main(void)
{
    const struct device *input_dev;
    int ret, val;
    int ret1, val1;

    input_dev = device_get_binding(INPUT_PORT);
    if (!input_dev) {
        printk("Erro ao acessar porta %s\n", INPUT_PORT);
        return;
    }

    ret = gpio_pin_configure(input_dev, INPUT_PIN, GPIO_INPUT);
    if (ret != 0) {
        printk("Erro ao configurar pino %d\n", INPUT_PIN);
        return;
    }
        

    ret1 = gpio_pin_configure(input_dev, INPUT_PIN2, GPIO_INPUT);
    if (ret != 0) {
        printk("Erro ao configurar pino %d\n", INPUT_PIN2);
        return;
    }

    while (1) {
        val = gpio_pin_get(input_dev, INPUT_PIN);
        val1 = gpio_pin_get(input_dev, INPUT_PIN2);
        printk("Valor do PTE20: %d\n", val);
        printk("Valor do PTE21: %d\n", val1);
        k_msleep(100);
    }

    while(1){
        
       
        k_msleep(10);
    }

     
}