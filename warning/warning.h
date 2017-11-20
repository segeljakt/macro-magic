/******************************************************************************
*     File Name           :     warning.h                                     *
*     Created By          :     Klas Segeljakt <klasseg@kth.se>               *
*     Creation Date       :     [2017-11-20 09:16]                            *
*     Last Modified       :     [????-??-?? ??:??]                            *
*     Description         :                                                   *
******************************************************************************/
#ifndef WARNING_H
#define WARNING_H
/*****************************************************************************/
#define STR_HELPER(X) #X
#define STR(X) STR_HELPER(X)
/*#define WARNING(MESSAGE) _Pragma __LINE__ __func__ #MESSAGE*/
#define WARNING(MESSAGE) _Pragma (MESSAGE)
/*****************************************************************************/
#endif /* WARNING_H */
