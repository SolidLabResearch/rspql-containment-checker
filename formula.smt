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
(declare-const	<p1_Employee>	RDFValue)
(declare-const	<p1_hasAge>	RDFValue)
(declare-const	<p2_window>	RDFValue)
(declare-const	<p_Property>	RDFValue)

; ------------ Literals -----------------------------

; ------------ Variables ----------------------------
(declare-const	<v2_age>	RDFValue)
(declare-const	<v2_person>	RDFValue)

; ------------ Assumption ---------------------------
(assert 
	(and 
		(and 
			(P <v2_person> <a> <p1_Employee> <p2_window>) 
			(P <v2_person> <p1_hasAge> <v2_age> <p2_window>) 
		)
		(and 
			(P <v2_person> <a> <p1_Employee> <p2_window>) 
			(P <v2_person> <p1_hasAge> <v2_age> <p2_window>) 
		)
	)
)

; ------------ Conjecture ---------------------------
(assert (not (exists ((<v1_age> RDFValue)(<v1_person> RDFValue)) 
	(and 
		(P <v1_person> <p1_hasAge> <v1_age> <p2_window>) 
		(and (= <v1_age> <v2_age>) )
	)
)))

; ------------ Check-Sat ----------------------------
(check-sat)
