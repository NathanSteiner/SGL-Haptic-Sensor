// Libraries
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/logging/log.h>

// Register Logger
LOG_MODULE_REGISTER(Haptic, LOG_LEVEL_DBG);

// Define Haptic Sensor
#define HAP_NODE DT_NODELABEL(haptic)
const struct i2c_dt_spec hapSensor = I2C_DT_SPEC_GET(HAP_NODE);

/////////////////////
//                 //
//     M A I N     //
//                 //
/////////////////////

int main(void){

        // Variables
        int err;
        uint8_t buffer[2];

        // Test I2C Bus
        if(!i2c_is_ready_dt(&hapSensor)){
                LOG_ERR("I2C bus is not ready.");
        }else{
                LOG_INF("Nominal");
        }

        ////////////// AUTO CALIBRATION //////////////

        // Auto calibration mode
        buffer[0] = 0x01;
        buffer[1] = 0x07;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write (auto calibration mode) to I2C device: %d", err);
        }else{
                LOG_INF("Auto Calibration Mode Nominal");
        }

        // Rated voltage (3)
        buffer[0] = 0x16;
        buffer[1] = 0x90;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write (rated voltage) to I2C device: %d", err);
        }else{
                LOG_INF("Rated Voltage Nominal");
        }

        // Overdrive voltage (3.6)
        buffer[0] = 0x17;
        buffer[1] = 0xA4;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write (overdrive voltage) to I2C device: %d", err);
        }else{
                LOG_INF("Nominal");
        }

        // Feedback control
        buffer[0] = 0x1A;
        buffer[1] = 0x36;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write (feedback control) to I2C device: %d", err);
        }else{
                LOG_INF("Nominal");
        }

        // Control 1
        buffer[0] = 0x1B;
        buffer[1] = 0x13;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write (control 1) to I2C device: %d", err);
        }else{
                LOG_INF("Nominal");
        }

        // Control 2
        buffer[0] = 0x1C;
        buffer[1] = 0xF5;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write (control 2) to I2C device: %d", err);
        }else{
                LOG_INF("Nominal");
        }

        // Control 3
        buffer[0] = 0x1D;
        buffer[1] = 0xA0;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write (control 3) to I2C device: %d", err);
        }else{
                LOG_INF("Nominal");
        }

        // GO
        buffer[0] = 0x0C;
        buffer[1] = 0x01;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write GO to I2C device: %d", err);
        }else{
                LOG_INF("Nominal");
        }
        k_msleep(1000);

        ////////////// HAPTIC TEST //////////////

        // Internal trigger mode
        buffer[0] = 0x01;
        buffer[1] = 0x00;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write (internal trigger mode) to I2C device: %d", err);
        }else{
                LOG_INF("Nominal");
        }

        k_msleep(5000);

        /////// Strong Click ///////
        buffer[0] = 0x04;
        buffer[1] = 0x01;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write (strong click) to I2C device: %d", err);
        }else{
                LOG_INF("Strong Click Nominal");
        }
        // GO
        buffer[0] = 0x0C;
        buffer[1] = 0x01;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write GO to I2C device: %d", err);
        }else{
                LOG_INF("GO Nominal");
        }
        k_msleep(2000);
        // STOP
        buffer[0] = 0x0C;
        buffer[1] = 0x00;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write STOP to I2C device: %d", err);
        }else{
                LOG_INF("STOP Nominal");
        }

        /////// Double Click ///////
        buffer[0] = 0x04;
        buffer[1] = 0x0A;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write (double click) to I2C device: %d", err);
        }else{
                LOG_INF("Double Click Nominal");
        }
        // GO
        buffer[0] = 0x0C;
        buffer[1] = 0x01;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write GO to I2C device: %d", err);
        }else{
                LOG_INF("GO Nominal");
        }
        k_msleep(2000);
        // STOP
        buffer[0] = 0x0C;
        buffer[1] = 0x00;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write STOP to I2C device: %d", err);
        }else{
                LOG_INF("STOP Nominal");
        }

        /////// Triple Click ///////
        buffer[0] = 0x04;
        buffer[1] = 0x0C;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write (triple click) to I2C device: %d", err);
        }else{
                LOG_INF("Triple Click Nominal");
        }
        // GO
        buffer[0] = 0x0C;
        buffer[1] = 0x01;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write GO to I2C device: %d", err);
        }else{
                LOG_INF("GO Nominal");
        }
        k_msleep(2000);
        // STOP
        buffer[0] = 0x0C;
        buffer[1] = 0x00;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write GO to I2C device: %d", err);
        }else{
                LOG_INF("STOP Nominal");
        }

        ////////////// VARIOUS EFFECTS //////////////
        
        k_msleep(7000);

        /////// Strong Buzz - 100% ///////
        buffer[0] = 0x04;
        buffer[1] = 0x0E;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write to I2C device: %d", err);
        }else{
                LOG_INF("Strong Buzz - 100");
        }
        // GO
        buffer[0] = 0x0C;
        buffer[1] = 0x01;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write GO to I2C device: %d", err);
        }else{
                LOG_INF("GO Nominal");
        }
        k_msleep(2000);
        // STOP
        buffer[0] = 0x0C;
        buffer[1] = 0x00;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write STOP to I2C device: %d", err);
        }else{
                LOG_INF("STOP Nominal");
        }
        
        /////// Long Double Sharp Click Strong ///////
        buffer[0] = 0x04;
        buffer[1] = 0x25;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write to I2C device: %d", err);
        }else{
                LOG_INF("Long Double Sharp Click Strong");
        }
        // GO
        buffer[0] = 0x0C;
        buffer[1] = 0x01;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write GO to I2C device: %d", err);
        }else{
                LOG_INF("GO Nominal");
        }
        k_msleep(2000);
        // STOP
        buffer[0] = 0x0C;
        buffer[1] = 0x00;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write STOP to I2C device: %d", err);
        }else{
                LOG_INF("STOP Nominal");
        }
        
        /////// Pulsing Strong ///////
        buffer[0] = 0x04;
        buffer[1] = 0x34;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write to I2C device: %d", err);
        }else{
                LOG_INF("Pulsing Strong");
        }
        // GO
        buffer[0] = 0x0C;
        buffer[1] = 0x01;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write GO to I2C device: %d", err);
        }else{
                LOG_INF("GO Nominal");
        }
        k_msleep(2000);
        // STOP
        buffer[0] = 0x0C;
        buffer[1] = 0x00;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write STOP to I2C device: %d", err);
        }else{
                LOG_INF("STOP Nominal");
        }
        


        /////// Transition Ramp Up Long Smooth 1 ///////
        buffer[0] = 0x04;
        buffer[1] = 0x52;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write to I2C device: %d", err);
        }else{
                LOG_INF("Transition Ramp Up Long Smooth 1");
        }
        // GO
        buffer[0] = 0x0C;
        buffer[1] = 0x01;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write GO to I2C device: %d", err);
        }else{
                LOG_INF("GO Nominal");
        }
        k_msleep(2000);
        // STOP
        buffer[0] = 0x0C;
        buffer[1] = 0x00;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write STOP to I2C device: %d", err);
        }else{
                LOG_INF("STOP Nominal");
        }
        


        /////// Smooth Hum 1 ///////
        buffer[0] = 0x77;
        buffer[1] = 0x0C;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write to I2C device: %d", err);
        }else{
                LOG_INF("Smooth Hum 1");
        }
        // GO
        buffer[0] = 0x0C;
        buffer[1] = 0x01;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write GO to I2C device: %d", err);
        }else{
                LOG_INF("GO Nominal");
        }
        k_msleep(2000);
        // STOP
        buffer[0] = 0x0C;
        buffer[1] = 0x00;
        err = i2c_write_dt(&hapSensor, buffer, 2);
        if(err){
                LOG_ERR("Failed to write STOP to I2C device: %d", err);
        }else{
                LOG_INF("STOP Nominal");
        }
}
