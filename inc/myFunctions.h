
/* IMPORTANTE: Este es un archivo para lectura de teclado utilizado
 * para hacer pruebas rápidas, dado que no resuelve de manera eficiente
 * el manejo de los rebotes.
 */


#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H
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

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/
//NO SE PUEDEN DECLARAR static LAS VARIABLES ACÁ!!!!!!
int32_t fd_out;
uint8_t tiltLed;
int tiltCounter, tiltFrec;
uint8_t teclas;

/*==================[external functions declaration]=========================*/

/** \brief inicializa el teclaso
 *
 * Inicializa el teclado
 *
 * \returns
 *
 */

/** \brief Teclado Get Flancos
 *
 * Indica si alguna tecla se presionó.
 *
 * \returns bits que indican en qué tecla se produjo un flanco
 *
 * \remarks Cuando se ejecuta esta función se ponen a cero todos los flancos
 */
//extern void procesarTeclasModBus(uint8_t value);

extern void procesarTeclas(uint8_t teclas);


/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef TECLADO_H */

