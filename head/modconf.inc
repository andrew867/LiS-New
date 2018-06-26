/* WARNING:  THIS FILE WAS GENERATED.  MANUAL CHANGES MAY BE LOST. */


extern struct streamtab clone_info ;
extern void _RP clone_init(void) ;
extern struct streamtab fifo_info ;
extern void _RP fifo_init(void) ;
extern void _RP fifo_term(void) ;
extern struct streamtab sloop_info ;
extern void _RP sloop_init(void) ;
extern void _RP sloop_term(void) ;
extern struct streamtab mux_info ;
extern struct streamtab printk_info ;
extern struct streamtab sad_info ;

int clone__0_majors[] = {231};
int fifo__0_majors[] = {232, 233};
int sloop__0_majors[] = {234};
int mux__0_majors[] = {235};
int printk__0_majors[] = {236};
int ldl__0_majors[] = {237};
int sad__0_majors[] = {238};
int ip2xinet_0_majors[] = {239};
int mtdrv__0_majors[] = {240};
int ss__0_majors[] = {241};

driver_config_t		lis_driver_config[] =
{
	{"clone-drvr", &clone_info, clone__0_majors, 1, 1, clone_init, NULL, -1},
	{"fifo", &fifo_info, fifo__0_majors, 2, 512, fifo_init, fifo_term, -1},
	{"loop-around", &sloop_info, sloop__0_majors, 1, 1, sloop_init, sloop_term, 0},
	{"mini-mux", &mux_info, mux__0_majors, 1, 1, NULL, NULL, 2},
	{"printk", &printk_info, printk__0_majors, 1, 1, NULL, NULL, -1},
	{"sad", &sad_info, sad__0_majors, 1, 1, NULL, NULL, -1},
} ;

device_config_t		lis_device_config[] =
{
} ;

extern struct streamtab		connld_info ;
extern struct streamtab		relay_info ;
extern struct streamtab		relay2_info ;

module_config_t		lis_module_config[] =
{
	{"",NULL,""}, /* empty 0th entry */	{"connld", &connld_info, "", -1},
	{"pipemod", NULL, "pipemod", -1},
	{"relay", &relay_info, "", 0},
	{"relay2", &relay2_info, "", 2},
	{"timod", NULL, "timod", -1},
	{"tirdwr", NULL, "tirdwr", -1},
} ;


#ifdef LIS_LOADABLE_SUPPORT

driver_obj_name_t		lis_drv_objnames[] =
{
    {ldl__0_majors, 1, "ldl_init", "ldl"},
    {ip2xinet_0_majors, 1, NULL, "ip_to_dlpi"},
    {mtdrv__0_majors, 1, NULL, "mtdrv"},
    {ss__0_majors, 1, NULL, "inet"},
} ;


#endif /* LIS_LOADABLE_SUPPORT */

autopush_init_t		lis_apush_init[] =
{
	{234,  9,  0, 1, {"relay", } },
} ;
