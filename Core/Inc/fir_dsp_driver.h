#ifndef FIR_DSP_DRIVER_H
#define FIR_DSP_DRIVER_H

#include "main.h"
#include <stdint.h>

/* Boyut Tanımlamaları */
#define N         32U             // Toplam DMA tampon boyutu (Düşük gecikme istersen 4U veya 2U yapabilirsin)
#define halfN     (N / 2U)        // Yarım tampon boyutu (16 örnek)
#define NUM_TAPS  36U             // MATLAB'dan alınan 36 FIR filtre katsayısı

/* Mod Seçimi (Adım adım test için):
 * 1: Mod 1 - Sadece DAC Sinüs Üretimi Testi
 * 2: Mod 2 - Filtresiz 8-Bit ADC -> DAC Doğrudan Aktarım Testi
 * 3: Mod 3 - 36 Katsayılı 8-Bit FIR Filtre Çalıştırma
 */
#define TEST_MODE 2


/* Fonksiyon Prototipleri */
void filter_init(void);
void filter_process(void);
void process_half_buffer(void);
void process_Cplt_buffer(void);
#endif
