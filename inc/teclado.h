
/* IMPORTANTE: Este es un archivo para lectura de teclado utilizado
 * para hacer pruebas rápidas, dado que no resuelve de manera eficiente
 * el manejo de los rebotes.
 */


#ifndef TECLADO_H
#define TECLADO_H
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
#define TECLADO_TEC1_BIT         0B0001
#define TECLADO_TEC2_BIT         0B0010
#define TECLADO_TEC3_BIT         0B0100
#define TECLADO_TEC4_BIT         0B1000

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

/** \brief inicializa el teclaso
 *
 * Inicializa el teclado
 *
 * \returns
 *
 */
extern void teclado_init(void);

/** \brief Teclado Get Flancos
 *
 * Indica si alguna tecla se presionó.
 *
 * \returns bits que indican en qué tecla se produjo un flanco
 *
 * \remarks Cuando se ejecuta esta función se ponen a cero todos los flancos
 */
extern uint8_t teclado_getFlancos(void);

extern void teclado_task(void);

extern void procesarTeclasModBus(uint8_t value);

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef TECLADO_H */

