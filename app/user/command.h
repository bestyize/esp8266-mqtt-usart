/*
 * command.h
 *
 *  Created on: 2019年5月10日
 *      Author: yize
 */

#ifndef APP_USER_COMMAND_H_
#define APP_USER_COMMAND_H_


#define TOPIC_LED_CONTROL "/mqtt/led/control"
#define TOPIC_DHT_CONTROL "/mqtt/dht11/control"
#define TOPIC_VOL_CONTROL "/mqtt/voltage/control"
#define TOPIC_PWM_CONTROL "/mqtt/pwm/control"


#define TOPIC_LED_STATUS  "/mqtt/led/status"
#define TOPIC_DHT_STATUS  "/mqtt/dht11/status"
#define TOPIC_VOL_STATUS  "/mqtt/voltage/status"
#define TOPIC_PWM_STATUS  "/mqtt/pwm/status"



/*自定义的通信格式，串口通信*/
#define CMD_RECEIVE_LED_ON      "led:1001"//显示
#define CMD_RECEIVE_LED_OFF     "led:1002"//取消显示
#define CMD_RECEIVE_LED_STATUS  "led:status:"


#define CMD_RECEIVE_DHT11_READ  	"dht:1003"
#define CMD_RECEIVE_DHT11_OFF   	"dht:1004"
#define CMD_RECEIVE_DHT11_STATUS  	"dht:status:"

#define CMD_VOLTAGE_READ        	"vol:1005"
#define CMD_VOLTAGE_OFF         	"vol:1006"
#define CMD_RECEIVE_VOLTAGE_STATUS  "vol:status:"



#define CMD_RUNTIME_READ        "tim:1007"//显示系统运行时间
#define CMD_RUNTIME_OFF         "tim:1008"//关闭显示系统运行时间

#define CMD_RECEIVE_PWM_ADJ     "pwm:"//data是PWM的占空比，1000-1100,最终值减去1000
#define CMD_RECEIVE_PWM_STATUS  "duty:"//PWM回复自身状态






#endif /* APP_USER_COMMAND_H_ */
