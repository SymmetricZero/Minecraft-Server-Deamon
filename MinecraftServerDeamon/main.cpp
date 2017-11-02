#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <pthread.h>
#include <unistd.h>

int Deamon = 1;
int threadonline = 0;

void *conswite(void *c)
{
	threadonline = 1;
	printf("Server will restart in 5 second, stop it?[y/]");
	if (getchar() == 'y')
	{
		Deamon = 0;
	}
	threadonline = 0;
	return 0;
}

int main()
{	
	pthread_t pt1;
	int error;
	do
	{
		system("java -Xms768M -Xmx1280M -jar forge-1.7.10-10.13.4.1558-1.7.10-universal.jar");
		error = pthread_create(&pt1, NULL, conswite, NULL);
		if (error != 0)
		{
			printf("Thread Create Error!");
			return -1;
		}
		sleep(5);
		if (threadonline == 1)
			pthread_cancel(pt1);
		pthread_join(pt1, NULL);
	} while (Deamon == 1);

	return 0;
}