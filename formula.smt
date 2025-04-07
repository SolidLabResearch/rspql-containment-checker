; ------------ Sort and Predicate -------------------
(declare-sort RDFValue 0)
(declare-fun P (RDFValue RDFValue RDFValue RDFValue) Bool)
(declare-fun f_str (RDFValue) RDFValue)
(declare-fun f_xsd_string (RDFValue) RDFValue)
(declare-fun f_datatype (RDFValue) RDFValue)
(declare-fun f_lcase (RDFValue) RDFValue)
(declare-fun f_round (RDFValue) RDFValue)
(declare-fun f_abs (RDFValue) RDFValue)
(declare-fun f_isliteral (RDFValue) Bool)
(declare-fun f_isuri (RDFValue) Bool)
(declare-fun f_contains (RDFValue RDFValue) Bool)
(declare-fun f_regex (RDFValue RDFValue) Bool)
(declare-fun f_add (RDFValue RDFValue) RDFValue)
(declare-fun f_sub (RDFValue RDFValue) RDFValue)
(declare-fun f_mul (RDFValue RDFValue) RDFValue)
(declare-fun f_div (RDFValue RDFValue) RDFValue)
(declare-fun f_lt (RDFValue RDFValue) Bool)
(declare-fun f_gt (RDFValue RDFValue) Bool)
(declare-fun f_leq (RDFValue RDFValue) Bool)
(declare-fun f_geq (RDFValue RDFValue) Bool)
(declare-fun f_bound (RDFValue) Bool)
(declare-const <default_graph> RDFValue)
(assert (forall ((s RDFValue)(p RDFValue)(o RDFValue)(g RDFValue)) (=> (P s p o g) (P s p o <default_graph>))))

; ------------ IRIs ---------------------------------
(declare-const	<a>	RDFValue)
(declare-const	<p0_Resourse>	RDFValue)
(declare-const	<p1_One>	RDFValue)
(declare-const	<p1_Person>	RDFValue)
(declare-const	<p1_hasAge>	RDFValue)
(declare-const	<p1_w1>	RDFValue)
(declare-const	<p_Property>	RDFValue)

; ------------ Literals -----------------------------

; ------------ Variables ----------------------------
(declare-const	<v2_x>	RDFValue)

; ------------ Assumption ---------------------------
(assert 
	(and 
		(and 
			(P <v2_x> <a> <p1_Person> <p1_w1>) 
			(P <v2_x> <p1_hasAge> <p1_One> <p1_w1>) 
		)
	)
)

; ------------ Conjecture ---------------------------
(assert (not (exists ((<v1_x> RDFValue)) 
	(and 
		(P <v1_x> <a> <p1_Person> <p1_w1>) 
		(and (= <v1_x> <v2_x>) )
	)
)))

; ------------ Check-Sat ----------------------------
(check-sat)
