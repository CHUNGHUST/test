typedef struct msp_fft_q15_params {
    uint16_t                length;             /*!< Length of the source data. */
    bool                    bitReverse;         /*!< Perform bit-reversal of input first. */
    const uint16_t          *bitReverseTable;   /*!< Pointer to the bit-reversal table descriptor to use with size greater than or equal to half the source length. This is not required if bitReverse is false. */
    const _q15              *twiddleTable;      /*!< Pointer to the twiddle coefficient table descriptor to use with size greater than or equal to half the source length. */
    const _q15              *splitTable;        /*!< Pointer to the split coefficient table with size greater than or equal to the source length. */
} msp_fft_q15_params;


msp_fft_q15_params params = {
    numSamples,									=> length param = 2048
    true,										=> bitReverse = 1
    msp_cmplx_bitrev_table_2048_ui16,           => uint16_t msp_cmplx_bitrev_table_2048_ui16[DSPLIB_TABLE_OFFSET+2048]
    msp_cmplx_twiddle_table_2048_q15,           => _q15 msp_cmplx_twiddle_table_2048_q15[DSPLIB_TABLE_OFFSET+2048]
    msp_split_table_2048_q15                    => _q15 msp_split_table_4096_q15[DSPLIB_TABLE_OFFSET+2048]
};



MAIN: msp_fft_scale_q15(&params, zArray);


       msp_fft_scale_q15(*param, *src)  
	   {
	  	    msp_status status;                          // Status of the operations
		    msp_cmplx_fft_q15_params  paramsCmplxFFT;   // Complex FFT params structure
		    msp_split_q15_params  paramsSplit;          // Split operation params structure
	    	
	    	
	    	/**/
//				typedef struct msp_cmplx_fft_q15_params {
//				    uint16_t                length;             /*!< Length of the source data. */
//				    bool                    bitReverse;         /*!< Perform bit-reversal of input first. */
//				    const uint16_t          *bitReverseTable;   /*!< Pointer to the bit-reversal table descriptor to use with size greater than or equal to source length. This is not required if bitReverse is false. */
//				    const _q15              *twiddleTable;      /*!< Pointer to the complex twiddle coefficient table descriptor to use with size greater than or equal to source length. */
//				} msp_cmplx_fft_q15_params;

//				typedef struct msp_split_q15_params {
//				    uint16_t                length;             /*!< Length of the source data. */
//				    const _q15              *splitTable;        /*!< Pointer to the split coefficient table with size greater than or equal to the source length. */
//				} msp_split_q15_params;
			/* */
			//Initialize complex FFT params structure. */
		    paramsCmplxFFT.length = params->length >> 1;          =>  length CmlxFFT = 1024
		    paramsCmplxFFT.bitReverse = params->bitReverse;           => bitReverse  = 1
		    paramsCmplxFFT.bitReverseTable = params->bitReverseTable; => _q15 msp_cmplx_twiddle_table_2048_q15[DSPLIB_TABLE_OFFSET+2048]
		    paramsCmplxFFT.twiddleTable = params->twiddleTable; => _q15 msp_split_table_4096_q15[DSPLIB_TABLE_OFFSET+2048]
		    
		    /* Perform N/2 complex FFT on real source with scaling. */
    		status = msp_cmplx_fft_scale_q15(&paramsCmplxFFT, src);
	   } 
	   


