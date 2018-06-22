#define GSM_SERIAL_BUFFER_LEN 256
char gsm_serial_buffer [GSM_SERIAL_BUFFER_LEN];

//Fill gsm_serial_buffer with zeros
void initialize_gsm_serial_buffer()
{
	for (int i = 0; i < GSM_SERIAL_BUFFER_LEN; i++)
	{
		gsm_serial_buffer[i] = 0;
	}
	gsm_serial_buffer[GSM_SERIAL_BUFFER_LEN - 1] = 0;
}

void setup()
{
	int message_n = 1; //Read the 1st SMS message
	
	//Initialize input buffer
	initialize_gsm_serial_buffer();
	
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
	
	//Read the message into a buffer...
	//...read from the hardware Serial connected to GSM Modem
	Serial.readBytes(gsm_serial_buffer, GSM_SERIAL_BUFFER_LEN);
	gsm_serial_buffer[GSM_SERIAL_BUFFER_LEN - 1] = 0; //Add NULL char
	
	/*
	 * The SMS message is now copied to 'gsm_serial_buffer'
	 * Do with it as you please.
	 */
}

void loop()
{
	//
}
