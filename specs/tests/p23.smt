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
(declare-const	<p1_Student>	RDFValue)
(declare-const	<p1_age>	RDFValue)
(declare-const	<p1_emailAddress>	RDFValue)
(declare-const	<p1_memberOf>	RDFValue)
(declare-const	<p1_nickName>	RDFValue)
(declare-const	<p1_sex>	RDFValue)
(declare-const	<p1_ssn>	RDFValue)
(declare-const	<p1_takesCourse>	RDFValue)
(declare-const	<p1_telephone>	RDFValue)
(declare-const	<p_Property>	RDFValue)

; ------------ Literals -----------------------------

; ------------ Variables ----------------------------
(declare-const	<v2_age>	RDFValue)
(declare-const	<v2_course>	RDFValue)
(declare-const	<v2_dept>	RDFValue)
(declare-const	<v2_email>	RDFValue)
(declare-const	<v2_sex>	RDFValue)
(declare-const	<v2_ssn>	RDFValue)
(declare-const	<v2_tel>	RDFValue)
(declare-const	<v2_x>	RDFValue)
(declare-const	<v2_z>	RDFValue)

; ------------ Assumption ---------------------------
(assert 
	(and 
		(P <v2_x> <a> <p1_Student> <default_graph>) 
		(P <v2_x> <p1_nickName> <v2_z> <default_graph>) 
		(P <v2_x> <p1_telephone> <v2_tel> <default_graph>) 
		(P <v2_x> <p1_ssn> <v2_ssn> <default_graph>) 
		(P <v2_x> <p1_sex> <v2_sex> <default_graph>) 
		(P <v2_x> <p1_memberOf> <v2_dept> <default_graph>) 
		(P <v2_x> <p1_emailAddress> <v2_email> <default_graph>) 
		(P <v2_x> <p1_age> <v2_age> <default_graph>) 
		(P <v2_x> <p1_takesCourse> <v2_course> <default_graph>) 
	)
)

; ------------ Check-Sat ----------------------------
(check-sat)
