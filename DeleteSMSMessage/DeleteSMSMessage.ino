void setup()
{
	int message_n = 1; //Delete the 1st SMS message
	
	//Setup the Modem Serial port
	Serial.begin(115200);
	
	//Send AT
	Serial.print("AT\r\n");
	delay(10000);
	
	//Send AT+CMGF=1
	Serial.print("AT+CMGF=1\r\n");
	delay(500);
	
	//Send AT+CPMS="SM"
	Serial.print("AT+CPMS=\"SM\"\r\n");
	delay(1000);
	
	//Send \r\n
	Serial.print("\r\n");
	delay(10000);
	
	//Send AT+CMGR=message_n
	Serial.print("AT+CMGR=");
	Serial.print(message_n);
	Serial.print("\r\n");
	delay(5000);
	
	//Send AT+CMGD=message_n
	Serial.print("AT+CMGD=");
	Serial.print(message_n);
	Serial.print("\r\n");
	
	/*
	 * The SMS message should now be deleted from
	 * the GSM Modem/SIM Card.
	 */
}

void loop()
{
	//
}
