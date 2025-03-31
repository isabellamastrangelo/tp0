#include "client.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */
	

	logger = iniciar_logger();

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"
	log_info (logger, "Hola! Soy un log");

	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();
	valor = config_get_string_value(config,"CLAVE");
	puerto = config_get_string_value(config,"PUERTO");
	ip = config_get_string_value(config,"IP");

	log_info(logger, "Valor de config: %s", valor);     //el %s es porque quiero poner un string ahi
	log_info(logger, "Puerto de config: %s", puerto);
	log_info(logger, "IP de config: %s", ip);
	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	// Loggeamos el valor de config


	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger()
{
	char* nombre_archivo = "tp0.log";//readline("> ");
	char* nombre_logger = "TP0_LOGGER"; //readline("> ");
	bool enconsola = 1; //readline("> ");
	t_log_level nivel = LOG_LEVEL_INFO;//readline(">");
	t_log* nuevo_logger = log_create (nombre_archivo, nombre_logger, enconsola, nivel);

	if (nuevo_logger == NULL) {
		printf("Error en el logger");
		abort();
	}

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	char* path = "cliente.config";
	t_config* nuevo_config = config_create(path);

	if (nuevo_config == NULL) {
		printf("Error en el config");
		abort();
	}
	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;
	leido = readline("> ");
	// La primera te la dejo de yapa
	while(strcmp(leido, "") != 0){
		log_info(logger, "Ingresado por pantalla: %s", leido);
		free(leido);
		leido = readline("> ");	
	}

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío


	// ¡No te olvides de liberar las lineas antes de regresar!
	
}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	log_destroy(logger);
	config_destroy(config);
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
}
