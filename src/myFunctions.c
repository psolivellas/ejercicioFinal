/* Copyright 2014, ACSE & CADIEEL
 *    ACSE   : http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/
 *    CADIEEL: http://www.cadieel.org.ar
 * All rights reserved.
 *
 *    or
 *
 * Copyright 2014, Your Name <youremail@domain.com>
 * All rights reserved.
 *
 *    or
 *
 * Copyright 2014, ACSE & CADIEEL & Your Name <youremail@domain.com
 *    ACSE   : http://www.sase.com.ar/asociacion-civil-sistemas-embebidos/ciaa/
 *    CADIEEL: http://www.cadieel.org.ar
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Short description of this file
 **
 ** Long description of this file
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup Template Template to start a new module
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "os.h"
#include "ciaak.h"

#include "../../ejercicioFinal/inc/teclado.h"
#include "../../ejercicioFinal/inc/myFunctions.h"

/*==================[macros and definitions]=================================*/
#define TECLADO_TOTAL_TECLAS     4

/*==================[internal data declaration]==============================*/
static int32_t fd_in;
static uint8_t estadoTeclas;
static uint8_t teclasFlancoUP;

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/





extern void procesarTeclasModBus(uint8_t value)
{
   //
   GetResource(BLOCK);

   tiltLed = (value & 0B00111111);

   ReleaseResource(BLOCK);
}


extern void procesarTeclas()
{
   uint8_t teclas;
   uint8_t outputs;

   //
   /* lee los flancos de las teclas */
   teclas = teclado_getFlancos();


   /* si se oprime la tecla parpadea el led */
   if (TECLADO_TEC1_BIT & teclas)
   {
      //Gira a la izquierda
      if (tiltLed != 0B000001)
      {
         tiltLed = (tiltLed >> 1);
      }
      else
      {
         tiltLed = 0B100000;
      }

      /* escribe el nuevo estado de las salidas */
      ciaaPOSIX_write(fd_out, &tiltLed, 1);
   }

   /* si se oprime la tecla parpadea el led */
   if (TECLADO_TEC2_BIT & teclas)
   {
      //Gira a la derecha
      if (tiltLed != 0B100000)
      {
         tiltLed = (tiltLed << 1);
      }
      else
      {
         tiltLed = 0B000001;
      }

      /* escribe el nuevo estado de las salidas */
      ciaaPOSIX_write(fd_out, &tiltLed, 1);
   }


   /* si se oprime la tecla 4 Decrementa la frecuencia de parpade0 del led */
   if (TECLADO_TEC3_BIT & teclas)
   {
      GetResource(BLOCK);

      //Decrementa frecuencia
      if (tiltFrec >= 1000)
      {
         //do Nothing, you cant decrement your frec. less than 100ms.
         tiltFrec = 1000;

         ciaaPOSIX_read(fd_out, &outputs, 1);
         outputs ^= 0B00000111;
         ciaaPOSIX_write(fd_out, &outputs, 1);
      }
      else
      {
         tiltFrec += 100;
      }

      ReleaseResource(BLOCK);
   }

   /* si se oprime la tecla 4 Incrementa la frecuencia de parpade0 del led */
   if (TECLADO_TEC4_BIT & teclas)
   {
      GetResource(BLOCK);

      //Incrementa Frecuencia
      if (tiltFrec <= 100)
      {
         //do Nothing, you cant increment your frec. over than 1000ms.
         tiltFrec = 100;

         ciaaPOSIX_read(fd_out, &outputs, 1);
         outputs ^= 0B00000111;
         ciaaPOSIX_write(fd_out, &outputs, 1);
      }
      else
      {
         tiltFrec -= 100;
      }

      ReleaseResource(BLOCK);
   }
}


/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
