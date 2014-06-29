#ifndef SOUND_H
#define SOUND_H


/*A função carrega data de um arquivo usando uma função do alut, e depois
manda as informações pro OpenAL como buffer. Depois é criado uma source para
tocar o buffer */
ALboolean Sound_LoadALData();

 /*Com os valores definidos para o Listener, a função manda pro 
 OpenAL eles*/
void Sound_SetListenerValues();

/*Libera memória alocada para Buffers e Sources */
void Sound_KillALData();

/* Retorna a Source */
ALuint Sound_Source();

#endif