/*
 * repost_interface.h
 *
 *  Created on: 2019Äê5ÔÂ10ÈÕ
 *      Author: yize
 */

#ifndef APP_USER_REPOST_INTERFACE_H_
#define APP_USER_REPOST_INTERFACE_H_
#include "mqtt.h"

void subscribeAllTopic(MQTT_Client* client);
void onCloudDataReceive(char *topic,char *cloudData);
void onUsartDataReceive(char *usartData);
void publishTopic(MQTT_Client* client,char *topic,char *message);
void subscribeTopic(MQTT_Client* client ,char *topic);
void usartSendStr(char* data);
void usartSendLine(char* data);





#endif /* APP_USER_REPOST_INTERFACE_H_ */
