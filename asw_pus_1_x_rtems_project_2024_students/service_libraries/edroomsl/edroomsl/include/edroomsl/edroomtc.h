/*
 * \file	edroomtc.h created for micro_tmtcunit_mmesp_project project
 * \brief
 *	
 * \author	Alberto Carrasco Gallardo, <acarrasco@srg.aut.uah.es>
 * 
 * \internal
 * Created: 	27/07/2011
 * Compiler: 	gcc/g++
 * Company:  Space Research Group, Universidad de Alcal�.
 * Copyright: Copryright (c) 2011, Alberto Carrasco Gallardo
 *
 * For further information, please visit http://srg.aut.uah.es
 *
 * This software is provided under the terms of the GNU General Public v2
 * Licence. A full copy of the GNU GPL is provided in the file COPYING
 * found in the development root of micro_tmtcunit_mmesp_project project.
 * 	
 */

#ifndef EDROOMTC_H_
#define EDROOMTC_H_

#define _EDROOM_HANDLE_IRQS

class CEDROOMDummyStream
{

    public:

        void open(const char *string, int dummy = 0){}
        void reopen(void){}
        void close(void){}
        int is_open(void){return 1;}
        int good(void){return 1;}

        CEDROOMDummyStream &operator<<(const char *string){return *this;}
        CEDROOMDummyStream &operator<<(const int &integer){return *this;}
        CEDROOMDummyStream &operator<<(const unsigned int &uint){return *this;}
        CEDROOMDummyStream &operator<<(const float &fnum){return *this;}
        CEDROOMDummyStream(){}
        CEDROOMDummyStream(const char *string){}
};

class CEDROOMstream
{

    public:

        void open(const char *string, int dummy = 0);
        void reopen(void);
        void close(void);
        int is_open(void);
        int good(void);

        CEDROOMstream &operator<<(const char *string);
        CEDROOMstream &operator<<(const int &integer);
        CEDROOMstream &operator<<(const unsigned int &uint);
        CEDROOMstream &operator<<(const float &fnum);
        CEDROOMstream();
        CEDROOMstream(const char *string);
};

extern CEDROOMstream EDROOMFDeb;


#endif /* EDROOMTC_H_ */
