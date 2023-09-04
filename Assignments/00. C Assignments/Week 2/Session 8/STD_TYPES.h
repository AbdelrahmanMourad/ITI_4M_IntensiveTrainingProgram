#ifndef STD_TYPES_H		// header guard file, part 1
/* 	 can't put dot {.} in definition 
	put underscore {_} instead */
#define STD_TYPES_H		// header guard file, part 2


/*	u8, u16, u32, s8, s16, s32, f32, f64	
				==>		are called alias		*/
				
//typedef 	Old_DataType_Name	New__DataType_Name
typedef		unsigned char 		u8;		//	1-byte
typedef		unsigned short int	u16;	//	2-bytes
typedef		unsigned int		u32;	//	4-bytes

typedef		signed char			s8;
typedef		signed short int	s16;	// short comes only with int
typedef		signed int			s32;

typedef		float				f32;
typedef		double				f64;
//	No need for long

#endif					// header guard file, part 3