
int led = D4;

int motion = 0;

void setup() 
{
    pinMode(led, OUTPUT);
}

void loop() 
{
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler);
    
    motion = rand()%3;
    if(motion == 1) Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "wave");
    else if(motion == 2) Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "pat");
    else if(motion == 0) Particle.publish("Deakin_RIOT_SIT210_Photon_Buddy", "nothing");
    
    delay(20000);
}

void myHandler(const char *event, const char *data)
{
    if(strcmp(data, "wave") == 0)
    {
        flash(100);
        flash(100);
        flash(100);
    }
    else if(strcmp(data, "pat") == 0)
    {
        flash(3000);
        flash(3000);
        flash(3000);
    }
}


void flash(int time)
{
    digitalWrite(led, HIGH);
	delay(time);
	digitalWrite(led, LOW);
	delay(1000);
}

