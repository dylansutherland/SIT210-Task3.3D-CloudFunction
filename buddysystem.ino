
int led = D4;

int motion = 0;

void setup() 
{
    pinMode(led, OUTPUT);
}

void loop() 
{
    motion = rand()%2;
    if(motion == 1) Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "wave");
    else if(motion == 0) Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "nothing");
    
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler);
    delay(10000);
}

void myHandler(const char *event, const char *data)
{
    if(strcmp(data, "wave") == 0)
    {
        flash();
        flash();
        flash();
    }
}


void flash()
{
    digitalWrite(led, HIGH);
	delay(100);
	digitalWrite(led, LOW);
	delay(100);
}
