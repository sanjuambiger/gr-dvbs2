/* -*- c++ -*- */
/* 
 * Copyright 2014 Ron Economos.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_DVBS2_LDPC_BB_IMPL_H
#define INCLUDED_DVBS2_LDPC_BB_IMPL_H

#include <dvbs2/ldpc_bb.h>

typedef struct{
    int table_length;
    int d[LDPC_ENCODE_TABLE_LENGTH];
    int p[LDPC_ENCODE_TABLE_LENGTH];
}ldpc_encode_table;

namespace gr {
  namespace dvbs2 {

    class ldpc_bb_impl : public ldpc_bb
    {
     private:
      unsigned int frame_size;
      unsigned int nbch;
      unsigned int code_rate;
      unsigned int q_val;
      unsigned int table_length;
      void ldpc_lookup_generate(void);
      ldpc_encode_table ldpc_encode;

      const static int ldpc_tab_1_4N[45][13];
      const static int ldpc_tab_1_3N[60][13];
      const static int ldpc_tab_2_5N[72][13];
      const static int ldpc_tab_1_2N[90][9];
      const static int ldpc_tab_3_5N[108][13];
      const static int ldpc_tab_2_3N[120][14];
      const static int ldpc_tab_3_4N[135][13];
      const static int ldpc_tab_4_5N[144][12];
      const static int ldpc_tab_5_6N[150][14];
      const static int ldpc_tab_8_9N[160][5];
      const static int ldpc_tab_9_10N[162][5];

      const static int ldpc_tab_1_4S[9][13];
      const static int ldpc_tab_1_3S[15][13];
      const static int ldpc_tab_2_5S[18][13];
      const static int ldpc_tab_1_2S[20][9];
      const static int ldpc_tab_3_5S[27][13];
      const static int ldpc_tab_2_3S[30][14];
      const static int ldpc_tab_3_4S[33][13];
      const static int ldpc_tab_4_5S[35][4];
      const static int ldpc_tab_5_6S[37][14];
      const static int ldpc_tab_8_9S[40][5];

      const static int ldpc_tab_13_45N[52][13];
      const static int ldpc_tab_9_20N[81][13];
      const static int ldpc_tab_11_20N[99][14];
      const static int ldpc_tab_26_45N[104][14];
      const static int ldpc_tab_28_45N[112][12];
      const static int ldpc_tab_23_36N[115][12];
      const static int ldpc_tab_25_36N[125][12];
      const static int ldpc_tab_13_18N[130][11];
      const static int ldpc_tab_7_9N[140][13];
      const static int ldpc_tab_90_180N[90][19];
      const static int ldpc_tab_96_180N[96][21];
      const static int ldpc_tab_100_180N[100][17];
      const static int ldpc_tab_104_180N[104][19];
      const static int ldpc_tab_116_180N[116][19];
      const static int ldpc_tab_124_180N[124][17];
      const static int ldpc_tab_128_180N[128][16];
      const static int ldpc_tab_132_180N[132][16];
      const static int ldpc_tab_135_180N[135][15];
      const static int ldpc_tab_140_180N[140][16];
      const static int ldpc_tab_154_180N[154][14];
      const static int ldpc_tab_18_30N[108][20];
      const static int ldpc_tab_20_30N[120][17];
      const static int ldpc_tab_22_30N[132][16];

     public:
      ldpc_bb_impl(dvbs2_code_rate_t rate, dvbs2_framesize_t framesize);
      ~ldpc_bb_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
		       gr_vector_int &ninput_items,
		       gr_vector_const_void_star &input_items,
		       gr_vector_void_star &output_items);
    };

  } // namespace dvbs2
} // namespace gr

#endif /* INCLUDED_DVBS2_LDPC_BB_IMPL_H */

