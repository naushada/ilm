#ifndef __MAIN_CC__
#define __MAIN_CC__

#include "protocol.h"
#include "middleware.h"

ACE_UINT8 loop_forever(void)
{
  ACE_Time_Value to(5);

  while(1)
  {
    ACE_Reactor::instance()->handle_events(to);
  }

  return(0);
}

int main(int count, char* param[])
{

  /*This is the hexdump of DISCOVER.*/
  uint8_t req[] = {0x01,0x01,0x06,0x00,0xde,0x10,0xa7,0xe6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x75,0xa4,0x01,0x4d,0x47,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0x82,0x53,0x63,0x35,0x01,0x01,0x3d,0x07,0x01,0xf8,0x75,0xa4,0x01,0x4d,0x47,0x0c,0x07,0x6d,0x6e,0x61,0x68,0x6d,0x65,0x64,0x3c,0x08,0x4d,0x53,0x46,0x54,0x20,0x35,0x2e,0x30,0x37,0x0e,0x01,0x03,0x06,0x0f,0x1f,0x21,0x2b,0x2c,0x2e,0x2f,0x77,0x79,0xf9,0xfc,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

  mna::dhcp::dhcp_t* pReq = (mna::dhcp::dhcp_t *)req;

  mna::dhcp::server s;

  s.rx(req, sizeof(req));
  s.rx(req, sizeof(req));

  mna::middleware mw("enp0s9");
  ACE_Reactor::instance()->register_handler(mna::middleware::instance(), ACE_Event_Handler::READ_MASK);

  loop_forever();

  return(0);
}


#endif /*__MAIN_CC__*/
