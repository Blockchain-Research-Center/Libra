#ifndef __prover
#define __prover

#include "linear_gkr/circuit_fast_track.h"
#include "linear_gkr/prime_field.h"
#include "linear_gkr/polynomial.h"
#include <ctime>
#include <cstring>
#include <utility>

class prover
{
public:
	prime_field::field_element v_u, v_v;
	int total_uv;
	layered_circuit C;
	prime_field::field_element* circuit_value[100];

	int sumcheck_layer_id, length_g, length_u, length_v;
	prime_field::field_element alpha, beta;
	const prime_field::field_element *r_0, *r_1;
	prime_field::field_element *one_minus_r_0, *one_minus_r_1;

	linear_poly *mult_array, *addV_array, *add_array;
	linear_poly *V_mult_add;
	prime_field::field_element *beta_g_r0, *beta_g_r1, *beta_u;
	clock_t total_time;
	void init_array(int);
	void get_circuit(const layered_circuit &from_verifier);
	prime_field::field_element* evaluate();
	void proof_init();
	void sumcheck_init(int layer_id, int bit_length_g, int bit_length_u, int bit_length_v, const prime_field::field_element &,
		const prime_field::field_element &, const prime_field::field_element*, const prime_field::field_element*, prime_field::field_element*, prime_field::field_element*);
	void sumcheck_phase1_init();
	void sumcheck_phase2_init(prime_field::field_element, const prime_field::field_element*, const prime_field::field_element*);
	quadratic_poly sumcheck_phase1_update(prime_field::field_element);
	quadratic_poly sumcheck_phase2_update(prime_field::field_element);
	prime_field::field_element V_res(const prime_field::field_element*, const prime_field::field_element*, const prime_field::field_element*, int, int);
	std::pair<prime_field::field_element, prime_field::field_element> sumcheck_finalize(prime_field::field_element);
	prover()
	{
		memset(circuit_value, 0, sizeof circuit_value);
	}
	~prover();
};

#endif