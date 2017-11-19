#include <unistd.h>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <pthread.h>
#include <csignal>

void *conswite(void *c)
{
	printf("Server will restart in 5 second, Any input can stop it.....");
	if (getchar())
		kill(0, SIGKILL);
}

int main()
{	
	pthread_t pt1;
	int error;
	while (true)
	{
		system("java -Xms768M -Xmx1280M -jar forge-1.7.10-10.13.4.1558-1.7.10-universal.jar");
		
		error = pthread_create(&pt1, NULL, conswite, NULL);
		if (error != 0)
		{
			printf("Thread Create Error!");
			return -1;
		}

		sleep(5);
		pthread_cancel(pt1);
		pthread_join(pt1, NULL);

		FILE *errorlog;
		errorlog = fopen("MSDError.log", "a+");
		if (errorlog == NULL)
		{
			printf("ErrorLog file read/write Error!");
			return -1;
		}
		
		time_t currtime;
		time(&currtime);
		fprintf(errorlog, "[%s]\n", ctime(&currtime));
		fclose(errorlog);
	}

	return 0;
}