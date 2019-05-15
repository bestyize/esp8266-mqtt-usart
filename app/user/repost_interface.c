#include "repost_interface.h"
#include "string.h"
#include "debug.h"
#include "osapi.h"
#include "command.h"
#include "driver/uart.h"
#include "c_types.h"


static MQTT_Client* my_client;

/**
 * ��ȡ������Ĳ���
 * cmd ����+����
 * dst ����
 * ���磺getMessage("led:status:led now is on","led:status:")�ķ��ؽ����:led now is on
 */
static char* getMessage(char* cmd,char *dst)
{
	int i = strlen(dst)-1;
	char* temp = (char*)(cmd + i);
	return temp;
}


/**
 * �������л��⣬������command.h���ж���
 * ��user_main.c�����mqttConnectedCb�����������
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
 * ������յ����ƶ�����
 * ��user_main.c�����mqttDataCb�����������
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
 * �����յ��������� �ڴ����жϷ������������
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
 * �������⣬Ĭ��retain=false qos=0
 */
void publishTopic(MQTT_Client* client,char *topic,char *message)
{
	MQTT_Publish(client, topic, message,strlen(message), 0, 0);
}

/**
 * ���Ļ���,Ĭ��qos=0
 */
void subscribeTopic(MQTT_Client* client,char *topic)
{
    MQTT_Subscribe(client, topic, 0);
}


/*
 * ���ڷ��ͺ���
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
 * ���ڷ��ͺ��� ��������
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

