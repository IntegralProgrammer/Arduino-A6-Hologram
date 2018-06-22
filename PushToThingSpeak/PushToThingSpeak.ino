void setup()
{
	//Setup the Modem Serial port
	Serial.begin(115200);
	
	//Send AT
	Serial.print("AT\r\n");
	delay(10000);
	
	//Send AT+CMGF=1
	Serial.print("AT+CMGF=1\r\n");
	delay(500);
	
	//Send AT+CSQ
	Serial.print("AT+CSQ\r\n");
	delay(1000);
	
	//Send AT+CGATT=1
	Serial.print("AT+CGATT=1\r\n");
	delay(1000);
	
	//Send AT+CGDCONT=1,"IP","hologram"
	Serial.print("AT+CGDCONT=1,\"IP\",\"hologram\"\r\n");
	delay(10000);
	
	//Send AT+CSTT="hologram","",""
	Serial.print("AT+CSTT=\"hologram\",\"\",\"\"\r\n");
	delay(10000);
	
	//Send AT+CIPSTATUS
	Serial.print("AT+CIPSTATUS\r\n");
	delay(500);
	
	//Send AT+CGACT=1,1
	Serial.print("AT+CGACT=1,1\r\n");
	delay(10000);
	
	//Send AT+CIPSTATUS
	Serial.print("AT+CIPSTATUS\r\n");
	delay(500);
	
	//Send AT+CIFSR
	Serial.print("AT+CIFSR\r\n");
	delay(10000);
	
	//Send AT+CIPSTATUS
	Serial.print("AT+CIPSTATUS\r\n");
	delay(500);
	
	//Send AT+CIPSTART="TCP","api.thingspeak.com",80
	Serial.print("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");
	delay(1000);
	
	//Send AT+CIPSTATUS
	Serial.print("AT+CIPSTATUS\r\n");
	delay(500);
	
	//Send data to ThingSpeak
	Serial.print("AT+CIPSEND\r\n");
	delay(50);
	
	/*
	 * Here is where ThingSpeak gets updated.
	 * - Replace 'PUT_KEY_HERE' with your ThingSpeak write API key.
	 * - Replace 'varname' with the name of the updated ThingSpeak variable
	 * - Replace 'variableValue' with new value for the updated ThingSpeak variable
	 * 
	 */
	Serial.print("GET /update?api_key=PUT_KEY_HERE&varname=");
	Serial.print("variableValue");
	Serial.print("\n\r\n");
	
	delay(50);
	Serial.print((char)26);
	
	delay(10000);
	
	//Send AT+CIPCLOSE
	Serial.print("AT+CIPCLOSE\r\n");
}

void loop()
{
	//
}
