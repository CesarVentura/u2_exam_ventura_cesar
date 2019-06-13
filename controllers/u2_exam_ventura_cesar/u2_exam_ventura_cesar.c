/*
 * File:          Robot1.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/differential_wheels.h>, etc.
 */
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/keyboard.h>
#include <webots/distance_sensor.h>
#include <webots/position_sensor.h>


#include <stdio.h>
#include <math.h>


 

/*
 * You may want to add macros here.
 */
#define TIME_STEP 64

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv)
{
  /* necessary to initialize webots stuff */
             wb_robot_init();
             wb_keyboard_enable(TIME_STEP);
             
          
  
             int key;
          

  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
   WbDeviceTag wheel_righ = wb_robot_get_device("motor_righ");
   WbDeviceTag wheel_left = wb_robot_get_device("motor_left");
  
   
   
     

    wb_motor_set_position(wheel_righ, INFINITY);
    wb_motor_set_position(wheel_left, INFINITY);
    
    
    WbDeviceTag dist_sensor = wb_robot_get_device("distance_sensor");
    wb_distance_sensor_enable(dist_sensor, TIME_STEP);
    double ds_value;
    
    
    WbDeviceTag position1 = wb_robot_get_device("velocimetro1");
    wb_position_sensor_enable(position1, TIME_STEP);
    double ds_pvalue;

    WbDeviceTag position2 = wb_robot_get_device("velocimetro2");
    wb_position_sensor_enable(position2, TIME_STEP);
    double ds_pvalue2;

    
    
    
    
    
   
   
  while (wb_robot_step(TIME_STEP) != -1) {


       key = wb_keyboard_get_key();
      
      
       ds_value =  wb_distance_sensor_get_value(dist_sensor);
       printf("dist_sensor%lf\n", ds_value);
       
       ds_pvalue = wb_position_sensor_get_value(position1);
       printf("position_sensor1%lf\n", ds_pvalue);
       
       ds_pvalue2 = wb_position_sensor_get_value(position2);
       printf("position_sensor2%lf\n", ds_pvalue2);
       
       
       
    

    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */

    /* Process sensor data here */

    /*

     * Enter here functions to send actuator commands, like:
     * wb_differential_wheels_set_speed(100.0,100.0);
     */
     //wb_motor_set_velocity(wheel_righ,-2);
     //wb_motor_set_velocity(wheel_left,-2);
     
     
     if (key == WB_KEYBOARD_UP)
     {
       wb_motor_set_velocity (wheel_righ, -6.36);
       wb_motor_set_velocity (wheel_left, -6.36);
       printf ("UP key pressed!\n");

     }

     else if (key == WB_KEYBOARD_DOWN)
     {
       wb_motor_set_velocity (wheel_righ, 0.2122);
       wb_motor_set_velocity (wheel_left, 0.2122);
       printf ("DOWN key pressed!\n");
     }

     else if (key == WB_KEYBOARD_RIGHT)
     {
       wb_motor_set_velocity(wheel_righ, 6.28);
       wb_motor_set_velocity(wheel_left, -6.28);
       printf ("LEFT key pressed!\n");
     }

     else if (key == WB_KEYBOARD_LEFT)
     {
       wb_motor_set_velocity(wheel_righ, -6.28);
       wb_motor_set_velocity(wheel_left, 6.28);
       printf ("RIGHT key pressed!\n");
     }

     else
     {
       wb_motor_set_velocity (wheel_righ, 0);
       wb_motor_set_velocity (wheel_left, 0);
     }
     
     
     
   
     
     
     
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}