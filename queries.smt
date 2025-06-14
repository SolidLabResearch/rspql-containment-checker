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
(declare-const	<p0_Resourse>	RDFValue)
(declare-const	<p1_x>	RDFValue)
(declare-const	<p2_w1>	RDFValue)
(declare-const	<p3_hasValue>	RDFValue)
(declare-const	<p3_relatesToProperty>	RDFValue)
(declare-const	<p_Property>	RDFValue)

; ------------ Literals -----------------------------

; ------------ Variables ----------------------------
(declare-const	<v1_o>	RDFValue)
(declare-const	<v1_s>	RDFValue)

; ------------ Assumption ---------------------------
(assert 
	(and 
		(and 
			(P <v1_s> <p3_hasValue> <v1_o> <p2_w1>) 
			(P <v1_s> <p3_relatesToProperty> <p1_x> <p2_w1>) 
		)
	)
)

; ------------ Conjecture ---------------------------
(assert (not (exists ((<v2_o2> RDFValue)(<v2_o> RDFValue)(<v2_s> RDFValue)) 
	(and 
		(and 
			(P <v2_s> <p3_hasValue> <v2_o> <p2_w1>) 
			(P <v2_s> <p3_relatesToProperty> <p1_x> <p2_w1>) 
		)
		(and (= <v2_o> <v1_o>) )
	)
)))

; ------------ Check-Sat ----------------------------
(check-sat)
