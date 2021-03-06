#ifndef SPI_DRIVER_H_INCLUDED
#define SPI_DRIVER_H_INCLUDED

#include <etk/etk.h>
#include <libopencm3/stm32/spi.h>


class SPIMasterDriver : public etk::Stream<SPIMasterDriver>
{
public:

    SPIMasterDriver(uint32 dr);
    void begin();
    void end();

    void set_timeout(uint32 millis) {
        to_ms = millis;
    }

    void put(char c);

    char read();

    void read(auto& buf, uint32 len)
	{
		//spi_enable(spid);
		for(uint32 i = 0; i < len; i++)
		    buf[i] = spi_read(spid);
		
		//spi_disable(spid);
	}

    uint8 transfer(uint8 data);

private:
    uint32 spid;
    uint32 to_ms;
};



extern SPIMasterDriver spi1;
extern SPIMasterDriver spi2;

#endif

