#include "repost_interface.h"
#include "string.h"
#include "debug.h"
#include "osapi.h"
#include "command.h"
#include "driver/uart.h"
#include "c_types.h"


static MQTT_Client* my_client;

/**
 * 获取命令附带的参数
 * cmd 命令+参数
 * dst 命令
 * 例如：getMessage("led:status:led now is on","led:status:")的返回结果是:led now is on
 */
static char* getMessage(char* cmd,char *dst)
{
	int i = strlen(dst)-1;
	char* temp = (char*)(cmd + i);
	return temp;
}


/**
 * 订阅所有话题，话题在command.h中有定义
 * 在user_main.c里面的mqttConnectedCb函数里面调用
 */
void subscribeAllTopic(MQTT_Client* client)
{
	subscribeTopic(client,TOPIC_LED_CONTROL);
	subscribeTopic(client,TOPIC_DHT_CONTROL);
	subscribeTopic(client,TOPIC_VOL_CONTROL);
	subscribeTopic(client,TOPIC_PWM_CONTROL);
	my_client=client;

}

/**
 * 处理接收到的云端数据
 * 在user_main.c里面的mqttDataCb函数里面调用
 */
void onCloudDataReceive(char *topic,char *cloudData)
{
	if(strstr(cloudData,CMD_RECEIVE_LED_ON))
	{
		usartSendStr(CMD_RECEIVE_LED_ON);
	}
	else if(strstr(cloudData,CMD_RECEIVE_LED_OFF))
	{
		usartSendStr(CMD_RECEIVE_LED_OFF);
	}
	else if(strstr(cloudData,CMD_RECEIVE_DHT11_READ))
	{
		usartSendStr(CMD_RECEIVE_DHT11_READ);
	}
	else if(strstr(cloudData,CMD_RECEIVE_DHT11_OFF))
	{
		usartSendStr(CMD_RECEIVE_DHT11_OFF);
	}
	else if(strstr(cloudData,CMD_VOLTAGE_READ))
	{
		usartSendStr(CMD_VOLTAGE_READ);
	}
	else if(strstr(cloudData,CMD_VOLTAGE_OFF))
	{
		usartSendStr(CMD_VOLTAGE_OFF);
	}
	else if(strstr(cloudData,CMD_RECEIVE_PWM_ADJ))
	{
		usartSendStr(CMD_RECEIVE_PWM_ADJ);
	}
}

/**
 * 当接收到串口数据 在串口中断服务函数里面调用
 */
void onUsartDataReceive(char *usartData)
{
	//Todo
	if(strstr(usartData,CMD_RECEIVE_LED_STATUS)!=NULL)
	{
		//process usartData
		char *message=getMessage(usartData,CMD_RECEIVE_LED_STATUS);
		usartSendLine(message);
		publishTopic(my_client,TOPIC_LED_STATUS,message);

	}
	if(strstr(usartData,CMD_RECEIVE_DHT11_STATUS)!=NULL)
	{
		//process usartData
		char *message=getMessage(usartData,CMD_RECEIVE_LED_STATUS);
		usartSendLine(message);
		publishTopic(my_client,TOPIC_DHT_STATUS,message);
	}
	if(strstr(usartData,CMD_RECEIVE_VOLTAGE_STATUS)!=NULL)
	{
		//process usartData
		char *message=getMessage(usartData,CMD_RECEIVE_LED_STATUS);
		usartSendLine(message);
		publishTopic(my_client,TOPIC_VOL_STATUS,message);
	}
	if(strstr(usartData,CMD_RECEIVE_PWM_STATUS)!=NULL)
	{
		//process usartData
		char *message=getMessage(usartData,CMD_RECEIVE_LED_STATUS);
		usartSendLine(message);
		publishTopic(my_client,TOPIC_PWM_STATUS,message);
	}

}

/**
 * 发布话题，默认retain=false qos=0
 */
void publishTopic(MQTT_Client* client,char *topic,char *message)
{
	MQTT_Publish(client, topic, message,strlen(message), 0, 0);
}

/**
 * 订阅话题,默认qos=0
 */
void subscribeTopic(MQTT_Client* client,char *topic)
{
    MQTT_Subscribe(client, topic, 0);
}


/*
 * 串口发送函数
 * */
void usartSendStr(char* data)
{
	int i;
	int len=strlen(data);
	for(i=0;i<len;i++)
	{
		uart_tx_one_char(UART0,*(data+i));
	}
}

/*
 * 串口发送函数 发送新行
 * */
void usartSendLine(char* data)
{
	int i;
	int len=strlen(data);
	for(i=0;i<len;i++)
	{
		uart_tx_one_char(UART0,*(data+i));
	}
	uart_tx_one_char(UART0,'\r');
	uart_tx_one_char(UART0,'\n');

}

