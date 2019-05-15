/*
 * command.h
 *
 *  Created on: 2019��5��10��
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



/*�Զ����ͨ�Ÿ�ʽ������ͨ��*/
#define CMD_RECEIVE_LED_ON      "led:1001"//��ʾ
#define CMD_RECEIVE_LED_OFF     "led:1002"//ȡ����ʾ
#define CMD_RECEIVE_LED_STATUS  "led:status:"


#define CMD_RECEIVE_DHT11_READ  	"dht:1003"
#define CMD_RECEIVE_DHT11_OFF   	"dht:1004"
#define CMD_RECEIVE_DHT11_STATUS  	"dht:status:"

#define CMD_VOLTAGE_READ        	"vol:1005"
#define CMD_VOLTAGE_OFF         	"vol:1006"
#define CMD_RECEIVE_VOLTAGE_STATUS  "vol:status:"



#define CMD_RUNTIME_READ        "tim:1007"//��ʾϵͳ����ʱ��
#define CMD_RUNTIME_OFF         "tim:1008"//�ر���ʾϵͳ����ʱ��

#define CMD_RECEIVE_PWM_ADJ     "pwm:"//data��PWM��ռ�ձȣ�1000-1100,����ֵ��ȥ1000
#define CMD_RECEIVE_PWM_STATUS  "duty:"//PWM�ظ�����״̬






#endif /* APP_USER_COMMAND_H_ */
