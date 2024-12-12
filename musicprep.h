void *mainTask(void *arg){
	getRes(&defWidth,&defHeight);
	MusicOn = true;
	fullscreen();
	Authentication();
	pthread_exit(NULL);
}

void *backgroundMusic(void *arg){
	while(MusicOn){
		PlaySound(TEXT("Song/Hotel.wav"),NULL,SND_SYNC);
	}
	pthread_exit(NULL);
}
