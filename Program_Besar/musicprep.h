void *mainTask(void *arg){
	MusicOn = true;
	fullscreen();
	vLogin();
	pthread_exit(NULL);
}

void *backgroundMusic(void *arg){
	while(MusicOn){
		PlaySound(TEXT("Song/Hotel.wav"),NULL,SND_SYNC);
	}
	pthread_exit(NULL);
}
