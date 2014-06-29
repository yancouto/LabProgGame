#include <stdio.h>
#include <stdlib.h>
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>

/* Buffer que vai guardar a informação do som */
ALuint Buffer;

/* Source vai ser uma "posição física" que "emite" o som */
ALuint Source;

/*  Posição da source */
ALfloat SourcePos[] = { 0.0, 0.0, 0.0 };

/* Velocidade da source */
ALfloat SourceVel[] = { 0.0, 0.0, 0.0 };


/* Posição do Listener */
ALfloat ListenerPos[] = { 0.0, 0.0, 0.0 };

/* Velocidade do Listener */
ALfloat ListenerVel[] = { 0.0, 0.0, 0.0 };

/* Orientação do Listener. 
/* (3 primeiros elementos são "at", últimos 3 são "up") */
/* (Precisam ser unidades de '1') */
ALfloat ListenerOri[] = { 0.0, 0.0, -1.0,  0.0, 1.0, 0.0 };

ALboolean Sound_LoadALData() {
	
	ALenum format;
	ALsizei size;          /* Variaveis para carregar */
	ALvoid* data;
	ALsizei freq;
	ALboolean loop;

 	/* Carrega a data no buffer */
	alGenBuffers(1, &Buffer);

	if(alGetError() != AL_NO_ERROR)
		return AL_FALSE;

	alutLoadWAVFile("PEiB.wav", &format, &data, &size, &freq, &loop);
	alBufferData(Buffer, format, data, size, freq);
	alutUnloadWAV(format, data, size, freq);

	/* Conecta o buffer com a source */
	alGenSources(1, &Source);

	if(alGetError() != AL_NO_ERROR)
		return AL_FALSE;

	alSourcei (Source, AL_BUFFER,   Buffer   );
	alSourcef (Source, AL_PITCH,    1.0      );
	alSourcef (Source, AL_GAIN,     1.0      );
	alSourcefv(Source, AL_POSITION, SourcePos);
	alSourcefv(Source, AL_VELOCITY, SourceVel);
	alSourcei (Source, AL_LOOPING,  loop     );

	/* Checa por erros e retorna */
	if(alGetError() == AL_NO_ERROR)
		return AL_TRUE;

	return AL_FALSE;
} 

void Sound_SetListenerValues() {
	alListenerfv(AL_POSITION,    ListenerPos);
	alListenerfv(AL_VELOCITY,    ListenerVel);
	alListenerfv(AL_ORIENTATION, ListenerOri);
}

ALuint Sound_Source() {
	return Source;
}
 
 
void KillALData()
{
	alDeleteBuffers(1, &Buffer);
	alDeleteSources(1, &Source);
	alutExit();
}