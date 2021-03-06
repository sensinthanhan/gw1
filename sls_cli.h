/*
|-------------------------------------------------------------------|
| HCMC University of Technology                                     |
| Telecommunications Departments                                    |
| Command Line Interface for Smart Lighting System (SLS)            |
| Version: 2.0                                                      |
| Author: sonvq@hcmut.edu.vn                                        |
| Date: 01/2019                                                     |
|-------------------------------------------------------------------|
*/
#include "sls.h"


#ifndef SLS_CLI_H_
#define SLS_CLI_H_

#define USING_SQL_SERVER_ENABLE	0
#if (USING_SQL_SERVER_ENABLE)
#define USING_SQL_SERVER
#endif


#define SIMULATION_BUILD_ENABLE	1
#if (SIMULATION_BUILD_ENABLE)
#define SIMULATION_BUILD
#endif



#define MAX_NUM_OF_NODE			100
#define ALL_NODE				2
#define ODD_NODE				1
#define EVEN_NODE				0



#define SLS_LED_HELLO			"led_hello"
#define SLS_LED_ON				"led_on"
#define SLS_LED_OFF				"led_off"
#define SLS_LED_DIM				"led_dim"
#define SLS_LED_REBOOT			"led_reboot"
#define SLS_GET_LED_STATUS		"get_led_status"

#define SLS_LED_TIMER_START		"node_timer_on"
#define SLS_LED_TIMER_STOP		"node_timer_off" 

#define SLS_GET_NW_STATUS		"get_nw_status"
#define SLS_GET_GW_STATUS		"get_gw_status"
#define SLS_GW_HELLO 			"gw_hello"
#define SLS_REPAIR_ROOT			"nw_repair_root"

#define SLS_SET_APP_KEY			"set_app_key"
#define SLS_GET_APP_KEY			"get_app_key"
#define SLS_APP_KEY_128 		"CAFEBEAFDEADFEEE0123456789ABCDEF"
#define AUTO_SET_APP_KEY		1

#define SLS_USING_AES_128		1  //set this to enable AES-128 encryption


typedef enum {false=0, true=1} bool;

struct sensor_data_t {
	float		temperature;
	float		light;
	float		pressure;
	float		humidity;
	float 		pir;
	float 		rain;

	//arduino
	float		oil_voltage;
	float		oil_current;
	float		water_voltage;
	float		water_current;
	float		pressure_voltage;
	float		pressure_current;
};

typedef struct sensor_data_t		sensor_data_t;

struct node_db_struct_t {
	uint8_t 	index;
	uint16_t	id;			/*0001xxxx xxxxxxxx */
	char    	ipv6_addr[40];						
	char		connected[1];
	int			num_req;
	int			num_rep;
	int 		num_timeout;
	uint8_t		last_cmd;
	uint16_t	last_err_code;
	int 		num_of_retrans;
	char		last_seen[20];
	char		app_key[32];
	uint8_t		key[16];
	uint8_t		channel_id;
	int 		rssi;
	int 		lqi;
	int 		pan_id;
	int		    tx_power;
	int 		num_emergency_msg;
	uint8_t 	last_emergency_msg[MAX_CMD_DATA_LEN];
	char		next_hop_addr[16];						//byte array
	char		next_hop_link_addr[40];					// link address string
	float		delay;
	double		rdr;									//request delivery rate
	uint16_t	challenge_code;
	uint16_t	challenge_code_res;
	bool		authenticated;
	bool		encryption_phase;
	uint16_t	cmd_seq;
	uint16_t	async_seq;
	float		async_prr;

	env_struct_t	sensor;
	sensor_data_t	sensor_db;
};


typedef struct node_db_struct_t		node_db_struct_t;

#endif /* SLS_CLI_H_ */
