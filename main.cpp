#include <iostream>
#include <stdlib.h>
#include "threshold_paillier.h"

using namespace std;
using namespace NTL;

int main()
{
	Threshold_Paillier threshold_paillier(512);											// key generation and distribution
	
	ZZ massage;
	massage = 34614984;																	// plaintext massage
		
    ZZ c = threshold_paillier.encrypt(massage);											// ciphertext c = encryption(massage)
	
	ZZ c1 = threshold_paillier.partial_decrypt(c, threshold_paillier.f1);				// partial decryption
	ZZ c2 = threshold_paillier.partial_decrypt(c, threshold_paillier.f2);
	ZZ c3 = threshold_paillier.partial_decrypt(c, threshold_paillier.f3);
	
	bool ZKP_check = threshold_paillier.ZKP_for_partial_decryption(c, c1, c2, c3);		// ZKP for partial decryption
	if(ZKP_check){cout << "ZKP for partial decrpytion is successful" << endl;}
	else{cout << "ZKP for partial decryption is failed" << endl;}
	
	ZZ dec_c = threshold_paillier.combine_partial_decrypt(c1, c2, c3);					// combine partial decryptions
	
	if (dec_c == massage){
        cout << "Encryption and distributed decryption is successful" << endl;
    }
	
    return 0;
}