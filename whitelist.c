/* whitelist.c
 * whitelist of machines that are known to work somehow
 * and all the workarounds
 */

// machine needs acpi_sleep=s3_bios
#define S3_BIOS     0x01
// machine needs acpi_sleep=s3_mode
#define S3_MODE     0x02
// machine needs "vbetool save / restore"
#define VBE_SAVE    0x04
// machine does not need / may not use "vbetool post"
#define VBE_NOPOST  0x08
// machine needs "radeontool light off"
#define RADEON_OFF  0x10
// machine is only "half known" - unverified entries from acpi-support 0.59
#define UNSURE      0x20

struct machine_entry
{
	const char *sys_vendor;
	const char *sys_product;
	const char *sys_version;
	const char *bios_version;
	unsigned int flags;
};

struct machine_entry whitelist[] = {
	{ "IBM",			"",		"ThinkPad X32",	"", RADEON_OFF|VBE_NOPOST|S3_BIOS|S3_MODE },
	{ "Hewlett Packard",	"",	"HP OmniBook XE3 GF           ","", VBE_SAVE },
	{ "ASUSTEK ",			"L3000D",		"",	"", VBE_SAVE },
	{ "TOSHIBA",			"Libretto L5/TNK",	"",	"", 0 },
	{ "TOSHIBA",			"Libretto L5/TNKW",	"",	"", 0 },
	{ "SHARP                           ",	"PC-AR10 *",	"",	"", VBE_NOPOST },

	// entries below are imported from acpi-support 0.59 and though "half known".
	{ "ASUSTeK Computer Inc.",	"L7000G series Notebook PC*", "","", VBE_SAVE|UNSURE },
	{ "ASUSTeK Computer Inc.",	"M6Ne*",		"",	"", VBE_SAVE|UNSURE },
	{ "ASUSTeK Computer Inc.",	"W5A*",			"",	"", VBE_SAVE|UNSURE },
	{ "Acer",			"TravelMate 290*",	"",	"", VBE_SAVE|UNSURE },
	{ "Acer",			"TravelMate 660*",	"",	"", VBE_SAVE|UNSURE },
	{ "Acer",			"Aspire 2000*",		"",	"", VBE_SAVE|UNSURE },
	{ "Acer, inc.",			"TravelMate 8100*",	"",	"", VBE_SAVE|UNSURE },
	{ "Acer, inc.",			"Aspire 3000*",		"",	"", VBE_SAVE|UNSURE },
	{ "Compaq",			"Armada    E500*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Inspiron 700m*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Inspiron 1200*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Inspiron 6000*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Inspiron 8100*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Inspiron 8200*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Inspiron 8600*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Inspiron 9300*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Latitude 110L*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Latitude D410*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Latitude D510*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Latitude D600*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Latitude D610*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Latitude D800*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Latitude D810*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Latitude X1*",		"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Latitude X300*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Inc.",			"Precision M20*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Inspiron 700m*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Inspiron 1200*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Inspiron 6000*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Inspiron 8100*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Inspiron 8200*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Inspiron 8600*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Inspiron 9300*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Latitude 110L*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Latitude D410*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Latitude D510*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Latitude D600*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Latitude D610*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Latitude D800*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Latitude D810*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Latitude X1*",		"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Latitude X300*",	"",	"", VBE_SAVE|UNSURE },
	{ "Dell Computer Corporation",	"Precision M20*",	"",	"", VBE_SAVE|UNSURE },
	{ "ECS",			"G556 Centrino*",	"",	"", VBE_SAVE|UNSURE },
	{ "FUJITSU",			"Amilo A7640*",		"",	"", VBE_SAVE|UNSURE },
	{ "FUJITSU",			"Amilo M*",		"",	"", VBE_SAVE|UNSURE },
	{ "FUJITSU",			"LifeBook S Series*",	"",	"", VBE_SAVE|UNSURE },
	{ "FUJITSU",			"LIFEBOOK S6120*",	"",	"", VBE_SAVE|UNSURE },
	{ "FUJITSU",			"LIFEBOOK P7010*",	"",	"", VBE_SAVE|UNSURE },
	{ "FUJITSU SIEMENS",		"Amilo A7640*",		"",	"", VBE_SAVE|UNSURE },
	{ "FUJITSU SIEMENS",		"Amilo M*",		"",	"", VBE_SAVE|UNSURE },
	{ "FUJITSU SIEMENS",		"LifeBook S Series*",	"",	"", VBE_SAVE|UNSURE },
	{ "FUJITSU SIEMENS",		"LIFEBOOK S6120*",	"",	"", VBE_SAVE|UNSURE },
	{ "FUJITSU SIEMENS",		"LIFEBOOK P7010*",	"",	"", VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Compaq nc4200*",	"",	"", VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Compaq nc4200*",	"",	"", VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Compaq nc6000*",	"",	"", VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Compaq nx6110*",	"",	"", VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Compaq nc6120*",	"",	"", VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Compaq nx6125*",	"",	"", VBE_SAVE|VBE_NOPOST|UNSURE },
	{ "Hewlett-Packard",		"HP Compaq nc6220*",	"",	"", VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Compaq nc6230*",	"",	"", VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Compaq nx8220*",	"",	"", VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Compaq nc8230*",	"",	"", VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Pavilion dv1000*",	"",	"", VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Pavilion zt3000*",	"",	"", VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Tablet PC Tx1100*",	"",	"", VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"HP Tablet PC TR1105*",	"",	"", VBE_SAVE|UNSURE },
	{ "Hewlett-Packard",		"Pavilion zd7000*",	"",	"", VBE_SAVE|UNSURE },
	// R40
	{ "IBM",			"2681*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2682*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2683*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2692*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2693*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2696*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2698*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2699*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2722*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2723*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2724*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2897*",		"",	"", VBE_SAVE|UNSURE },
	// R50/p
	{ "IBM",			"1829*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1830*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1831*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1832*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1833*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1836*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1840*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1841*",		"",	"", VBE_SAVE|UNSURE },
	/* R50e needs not yet implemented save_video_pci_state :-(
	{ "IBM",			"1834*",		"",	"", UNSURE },
	{ "IBM",			"1842*",		"",	"", UNSURE },
	{ "IBM",			"2670*",		"",	"", UNSURE },
	*/
	// R52
	{ "IBM",			"1846*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1847*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1848*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1849*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1850*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1870*",		"",	"", VBE_SAVE|UNSURE },
	// T21
	{ "IBM",			"2647*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2648*",		"",	"", VBE_SAVE|UNSURE },
	// T23
	{ "IBM",			"475S*",		"",	"", VBE_SAVE|UNSURE },
	// T40/T41/T42/p
	{ "IBM",			"2373*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2374*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2375*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2376*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2378*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2379*",		"",	"", VBE_SAVE|UNSURE },
	// T43
	{ "IBM",			"1871*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1872*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1873*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1874*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1875*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1876*",		"",	"", VBE_SAVE|UNSURE },
	// T43/p
	{ "IBM",			"2668*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2669*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2678*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2679*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2686*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2687*",		"",	"", VBE_SAVE|UNSURE },
	// X30
	{ "IBM",			"2672*",		"",	"", VBE_SAVE|UNSURE|RADEON_OFF },
	{ "IBM",			"2673*",		"",	"", VBE_SAVE|UNSURE|RADEON_OFF },
	{ "IBM",			"2884*",		"",	"", VBE_SAVE|UNSURE|RADEON_OFF },
	{ "IBM",			"2885*",		"",	"", VBE_SAVE|UNSURE|RADEON_OFF },
	{ "IBM",			"2890*",		"",	"", VBE_SAVE|UNSURE|RADEON_OFF },
	{ "IBM",			"2891*",		"",	"", VBE_SAVE|UNSURE|RADEON_OFF },
	// X40
	{ "IBM",			"2369*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2370*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2371*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2372*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2382*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2386*",		"",	"", VBE_SAVE|UNSURE },
	// X41
	{ "IBM",			"1864*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1865*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2525*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2526*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2527*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"2528*",		"",	"", VBE_SAVE|UNSURE },
	// X41 Tablet
	{ "IBM",			"1866*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1867*",		"",	"", VBE_SAVE|UNSURE },
	{ "IBM",			"1869*",		"",	"", VBE_SAVE|UNSURE },

	{ "Samsung Electronics",	"NX05S*",		"",	"", VBE_SAVE|UNSURE },
	{ "SHARP Corporation",		"PC-MM20 Series*",	"",	"", VBE_SAVE|UNSURE },
	{ "Sony Corporation",		"PCG-U101*",		"",	"", VBE_SAVE|UNSURE },

	{ "TOSHIBA",			"libretto U100*",	"",	"", VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"P4000*",		"",	"", VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"PORTEGE A100*",	"",	"", VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"PORTEGE A200*",	"",	"", VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"PORTEGE M200*",	"",	"", VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"PORTEGE R200*",	"",	"", VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"Satellite 1900*",	"",	"", VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"TECRA A2*",		"",	"", VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"TECRA A5*",		"",	"", VBE_SAVE|UNSURE },
	{ "TOSHIBA",			"TECRA M2*",		"",	"", VBE_SAVE|UNSURE },
	{ NULL }
};
