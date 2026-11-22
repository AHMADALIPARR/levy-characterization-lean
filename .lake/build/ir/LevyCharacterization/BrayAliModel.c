// Lean compiler output
// Module: LevyCharacterization.BrayAliModel
// Imports: public import Init public meta import Init
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
uint8_t lean_nat_dec_eq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_ham4(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_ham4___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_matVec4(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_darkVec4(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_darkVec4___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_ham3(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_ham3___boxed(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_secularPoly(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_eps__exact__of__energy(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_p__rare__secular__of__energy(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_kappa__paper(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_kappa__onshell(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_eps__bounds(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_lindblad__prob__factor(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Add___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Add(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Add___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Sub___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Sub(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Sub___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Smul___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Smul(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Smul___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Mul___redArg(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Mul(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Mul___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Trace___redArg(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Trace(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Trace___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_SZ(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_SX(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_I2(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_effective__h2(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_lindblad__rhs(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_innovation__step(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_ham4(lean_object* v_F_1_, lean_object* v_t_2_, lean_object* v_U_3_, lean_object* v_D_4_, lean_object* v_i_5_, lean_object* v_j_6_){
_start:
{
lean_object* v___x_10_; uint8_t v___x_11_; 
v___x_10_ = lean_unsigned_to_nat(0u);
v___x_11_ = lean_nat_dec_eq(v_i_5_, v___x_10_);
if (v___x_11_ == 0)
{
lean_object* v___x_12_; uint8_t v___x_13_; 
v___x_12_ = lean_unsigned_to_nat(1u);
v___x_13_ = lean_nat_dec_eq(v_i_5_, v___x_12_);
if (v___x_13_ == 0)
{
lean_object* v___x_14_; uint8_t v___x_15_; 
lean_dec(v_D_4_);
v___x_14_ = lean_unsigned_to_nat(2u);
v___x_15_ = lean_nat_dec_eq(v_i_5_, v___x_14_);
if (v___x_15_ == 0)
{
lean_object* v___x_16_; uint8_t v___x_17_; 
v___x_16_ = lean_unsigned_to_nat(3u);
v___x_17_ = lean_nat_dec_eq(v_i_5_, v___x_16_);
if (v___x_17_ == 0)
{
lean_object* v_zero_18_; 
lean_dec(v_t_2_);
v_zero_18_ = lean_ctor_get(v_F_1_, 0);
lean_inc(v_zero_18_);
lean_dec_ref(v_F_1_);
return v_zero_18_;
}
else
{
uint8_t v___x_19_; 
v___x_19_ = lean_nat_dec_eq(v_j_6_, v___x_10_);
if (v___x_19_ == 0)
{
uint8_t v___x_20_; 
v___x_20_ = lean_nat_dec_eq(v_j_6_, v___x_12_);
if (v___x_20_ == 0)
{
uint8_t v___x_21_; 
lean_dec(v_t_2_);
v___x_21_ = lean_nat_dec_eq(v_j_6_, v___x_16_);
if (v___x_21_ == 0)
{
lean_object* v_zero_22_; 
v_zero_22_ = lean_ctor_get(v_F_1_, 0);
lean_inc(v_zero_22_);
lean_dec_ref(v_F_1_);
return v_zero_22_;
}
else
{
lean_dec_ref(v_F_1_);
lean_inc(v_U_3_);
return v_U_3_;
}
}
else
{
goto v___jp_7_;
}
}
else
{
goto v___jp_7_;
}
}
}
else
{
uint8_t v___x_23_; 
v___x_23_ = lean_nat_dec_eq(v_j_6_, v___x_10_);
if (v___x_23_ == 0)
{
uint8_t v___x_24_; 
v___x_24_ = lean_nat_dec_eq(v_j_6_, v___x_12_);
if (v___x_24_ == 0)
{
uint8_t v___x_25_; 
lean_dec(v_t_2_);
v___x_25_ = lean_nat_dec_eq(v_j_6_, v___x_14_);
if (v___x_25_ == 0)
{
lean_object* v_zero_26_; 
v_zero_26_ = lean_ctor_get(v_F_1_, 0);
lean_inc(v_zero_26_);
lean_dec_ref(v_F_1_);
return v_zero_26_;
}
else
{
lean_dec_ref(v_F_1_);
lean_inc(v_U_3_);
return v_U_3_;
}
}
else
{
goto v___jp_7_;
}
}
else
{
goto v___jp_7_;
}
}
}
else
{
uint8_t v___x_27_; 
v___x_27_ = lean_nat_dec_eq(v_j_6_, v___x_12_);
if (v___x_27_ == 0)
{
lean_object* v___x_28_; uint8_t v___x_29_; 
lean_dec(v_D_4_);
v___x_28_ = lean_unsigned_to_nat(2u);
v___x_29_ = lean_nat_dec_eq(v_j_6_, v___x_28_);
if (v___x_29_ == 0)
{
lean_object* v___x_30_; uint8_t v___x_31_; 
v___x_30_ = lean_unsigned_to_nat(3u);
v___x_31_ = lean_nat_dec_eq(v_j_6_, v___x_30_);
if (v___x_31_ == 0)
{
lean_object* v_zero_32_; 
lean_dec(v_t_2_);
v_zero_32_ = lean_ctor_get(v_F_1_, 0);
lean_inc(v_zero_32_);
lean_dec_ref(v_F_1_);
return v_zero_32_;
}
else
{
goto v___jp_7_;
}
}
else
{
goto v___jp_7_;
}
}
else
{
lean_object* v_two_33_; lean_object* v_div_34_; lean_object* v___x_35_; 
lean_dec(v_t_2_);
v_two_33_ = lean_ctor_get(v_F_1_, 2);
lean_inc(v_two_33_);
v_div_34_ = lean_ctor_get(v_F_1_, 7);
lean_inc(v_div_34_);
lean_dec_ref(v_F_1_);
v___x_35_ = lean_apply_2(v_div_34_, v_D_4_, v_two_33_);
return v___x_35_;
}
}
}
else
{
uint8_t v___x_36_; 
v___x_36_ = lean_nat_dec_eq(v_j_6_, v___x_10_);
if (v___x_36_ == 0)
{
lean_object* v___x_37_; uint8_t v___x_38_; 
lean_dec(v_D_4_);
v___x_37_ = lean_unsigned_to_nat(2u);
v___x_38_ = lean_nat_dec_eq(v_j_6_, v___x_37_);
if (v___x_38_ == 0)
{
lean_object* v___x_39_; uint8_t v___x_40_; 
v___x_39_ = lean_unsigned_to_nat(3u);
v___x_40_ = lean_nat_dec_eq(v_j_6_, v___x_39_);
if (v___x_40_ == 0)
{
lean_object* v_zero_41_; 
lean_dec(v_t_2_);
v_zero_41_ = lean_ctor_get(v_F_1_, 0);
lean_inc(v_zero_41_);
lean_dec_ref(v_F_1_);
return v_zero_41_;
}
else
{
goto v___jp_7_;
}
}
else
{
goto v___jp_7_;
}
}
else
{
lean_object* v_two_42_; lean_object* v_div_43_; lean_object* v_neg_44_; lean_object* v___x_45_; lean_object* v___x_46_; 
lean_dec(v_t_2_);
v_two_42_ = lean_ctor_get(v_F_1_, 2);
lean_inc(v_two_42_);
v_div_43_ = lean_ctor_get(v_F_1_, 7);
lean_inc(v_div_43_);
v_neg_44_ = lean_ctor_get(v_F_1_, 8);
lean_inc(v_neg_44_);
lean_dec_ref(v_F_1_);
v___x_45_ = lean_apply_2(v_div_43_, v_D_4_, v_two_42_);
v___x_46_ = lean_apply_1(v_neg_44_, v___x_45_);
return v___x_46_;
}
}
v___jp_7_:
{
lean_object* v_neg_8_; lean_object* v___x_9_; 
v_neg_8_ = lean_ctor_get(v_F_1_, 8);
lean_inc(v_neg_8_);
lean_dec_ref(v_F_1_);
v___x_9_ = lean_apply_1(v_neg_8_, v_t_2_);
return v___x_9_;
}
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_ham4___boxed(lean_object* v_F_47_, lean_object* v_t_48_, lean_object* v_U_49_, lean_object* v_D_50_, lean_object* v_i_51_, lean_object* v_j_52_){
_start:
{
lean_object* v_res_53_; 
v_res_53_ = lp_levy_x2dcharacterization_BrayAli_ham4(v_F_47_, v_t_48_, v_U_49_, v_D_50_, v_i_51_, v_j_52_);
lean_dec(v_j_52_);
lean_dec(v_i_51_);
lean_dec(v_U_49_);
return v_res_53_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_matVec4(lean_object* v_F_54_, lean_object* v_A_55_, lean_object* v_v_56_, lean_object* v_i_57_){
_start:
{
lean_object* v_add_58_; lean_object* v_mul_59_; lean_object* v___x_60_; lean_object* v___x_61_; lean_object* v___x_62_; lean_object* v___x_63_; lean_object* v___x_64_; lean_object* v___x_65_; lean_object* v___x_66_; lean_object* v___x_67_; lean_object* v___x_68_; lean_object* v___x_69_; lean_object* v___x_70_; lean_object* v___x_71_; lean_object* v___x_72_; lean_object* v___x_73_; lean_object* v___x_74_; lean_object* v___x_75_; lean_object* v___x_76_; lean_object* v___x_77_; lean_object* v___x_78_; 
v_add_58_ = lean_ctor_get(v_F_54_, 4);
lean_inc_n(v_add_58_, 3);
v_mul_59_ = lean_ctor_get(v_F_54_, 6);
lean_inc_n(v_mul_59_, 4);
lean_dec_ref(v_F_54_);
v___x_60_ = lean_unsigned_to_nat(0u);
lean_inc_n(v_A_55_, 3);
lean_inc_n(v_i_57_, 3);
v___x_61_ = lean_apply_2(v_A_55_, v_i_57_, v___x_60_);
lean_inc_n(v_v_56_, 3);
v___x_62_ = lean_apply_1(v_v_56_, v___x_60_);
v___x_63_ = lean_apply_2(v_mul_59_, v___x_61_, v___x_62_);
v___x_64_ = lean_unsigned_to_nat(1u);
v___x_65_ = lean_apply_2(v_A_55_, v_i_57_, v___x_64_);
v___x_66_ = lean_apply_1(v_v_56_, v___x_64_);
v___x_67_ = lean_apply_2(v_mul_59_, v___x_65_, v___x_66_);
v___x_68_ = lean_apply_2(v_add_58_, v___x_63_, v___x_67_);
v___x_69_ = lean_unsigned_to_nat(2u);
v___x_70_ = lean_apply_2(v_A_55_, v_i_57_, v___x_69_);
v___x_71_ = lean_apply_1(v_v_56_, v___x_69_);
v___x_72_ = lean_apply_2(v_mul_59_, v___x_70_, v___x_71_);
v___x_73_ = lean_unsigned_to_nat(3u);
v___x_74_ = lean_apply_2(v_A_55_, v_i_57_, v___x_73_);
v___x_75_ = lean_apply_1(v_v_56_, v___x_73_);
v___x_76_ = lean_apply_2(v_mul_59_, v___x_74_, v___x_75_);
v___x_77_ = lean_apply_2(v_add_58_, v___x_72_, v___x_76_);
v___x_78_ = lean_apply_2(v_add_58_, v___x_68_, v___x_77_);
return v___x_78_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_darkVec4(lean_object* v_F_79_, lean_object* v_i_80_){
_start:
{
lean_object* v___x_81_; uint8_t v___x_82_; 
v___x_81_ = lean_unsigned_to_nat(2u);
v___x_82_ = lean_nat_dec_eq(v_i_80_, v___x_81_);
if (v___x_82_ == 0)
{
lean_object* v___x_83_; uint8_t v___x_84_; 
v___x_83_ = lean_unsigned_to_nat(3u);
v___x_84_ = lean_nat_dec_eq(v_i_80_, v___x_83_);
if (v___x_84_ == 0)
{
lean_object* v_zero_85_; 
v_zero_85_ = lean_ctor_get(v_F_79_, 0);
lean_inc(v_zero_85_);
lean_dec_ref(v_F_79_);
return v_zero_85_;
}
else
{
lean_object* v_one_86_; lean_object* v_neg_87_; lean_object* v___x_88_; 
v_one_86_ = lean_ctor_get(v_F_79_, 1);
lean_inc(v_one_86_);
v_neg_87_ = lean_ctor_get(v_F_79_, 8);
lean_inc(v_neg_87_);
lean_dec_ref(v_F_79_);
v___x_88_ = lean_apply_1(v_neg_87_, v_one_86_);
return v___x_88_;
}
}
else
{
lean_object* v_one_89_; 
v_one_89_ = lean_ctor_get(v_F_79_, 1);
lean_inc(v_one_89_);
lean_dec_ref(v_F_79_);
return v_one_89_;
}
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_darkVec4___boxed(lean_object* v_F_90_, lean_object* v_i_91_){
_start:
{
lean_object* v_res_92_; 
v_res_92_ = lp_levy_x2dcharacterization_BrayAli_darkVec4(v_F_90_, v_i_91_);
lean_dec(v_i_91_);
return v_res_92_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_ham3(lean_object* v_F_93_, lean_object* v_t_94_, lean_object* v_U_95_, lean_object* v_D_96_, lean_object* v_i_97_, lean_object* v_j_98_){
_start:
{
lean_object* v_zero_99_; lean_object* v_two_100_; lean_object* v_mul_101_; lean_object* v_div_102_; lean_object* v_neg_103_; lean_object* v_sqrt_104_; lean_object* v___x_105_; lean_object* v_s_106_; lean_object* v___x_107_; uint8_t v___x_108_; 
v_zero_99_ = lean_ctor_get(v_F_93_, 0);
lean_inc(v_zero_99_);
v_two_100_ = lean_ctor_get(v_F_93_, 2);
lean_inc_n(v_two_100_, 2);
v_mul_101_ = lean_ctor_get(v_F_93_, 6);
lean_inc(v_mul_101_);
v_div_102_ = lean_ctor_get(v_F_93_, 7);
lean_inc(v_div_102_);
v_neg_103_ = lean_ctor_get(v_F_93_, 8);
lean_inc(v_neg_103_);
v_sqrt_104_ = lean_ctor_get(v_F_93_, 9);
lean_inc(v_sqrt_104_);
lean_dec_ref(v_F_93_);
v___x_105_ = lean_apply_1(v_sqrt_104_, v_two_100_);
v_s_106_ = lean_apply_2(v_mul_101_, v___x_105_, v_t_94_);
v___x_107_ = lean_unsigned_to_nat(0u);
v___x_108_ = lean_nat_dec_eq(v_i_97_, v___x_107_);
if (v___x_108_ == 0)
{
lean_object* v___x_109_; uint8_t v___x_110_; 
v___x_109_ = lean_unsigned_to_nat(1u);
v___x_110_ = lean_nat_dec_eq(v_i_97_, v___x_109_);
if (v___x_110_ == 0)
{
lean_object* v___x_111_; uint8_t v___x_112_; 
lean_dec(v_div_102_);
lean_dec(v_two_100_);
lean_dec(v_D_96_);
v___x_111_ = lean_unsigned_to_nat(2u);
v___x_112_ = lean_nat_dec_eq(v_i_97_, v___x_111_);
if (v___x_112_ == 0)
{
lean_dec(v_s_106_);
lean_dec(v_neg_103_);
return v_zero_99_;
}
else
{
uint8_t v___x_113_; 
v___x_113_ = lean_nat_dec_eq(v_j_98_, v___x_107_);
if (v___x_113_ == 0)
{
uint8_t v___x_114_; 
v___x_114_ = lean_nat_dec_eq(v_j_98_, v___x_109_);
if (v___x_114_ == 0)
{
uint8_t v___x_115_; 
lean_dec(v_s_106_);
lean_dec(v_neg_103_);
v___x_115_ = lean_nat_dec_eq(v_j_98_, v___x_111_);
if (v___x_115_ == 0)
{
return v_zero_99_;
}
else
{
lean_dec(v_zero_99_);
lean_inc(v_U_95_);
return v_U_95_;
}
}
else
{
lean_object* v___x_116_; 
lean_dec(v_zero_99_);
v___x_116_ = lean_apply_1(v_neg_103_, v_s_106_);
return v___x_116_;
}
}
else
{
lean_object* v___x_117_; 
lean_dec(v_zero_99_);
v___x_117_ = lean_apply_1(v_neg_103_, v_s_106_);
return v___x_117_;
}
}
}
else
{
uint8_t v___x_118_; 
v___x_118_ = lean_nat_dec_eq(v_j_98_, v___x_109_);
if (v___x_118_ == 0)
{
lean_object* v___x_119_; uint8_t v___x_120_; 
lean_dec(v_div_102_);
lean_dec(v_two_100_);
lean_dec(v_D_96_);
v___x_119_ = lean_unsigned_to_nat(2u);
v___x_120_ = lean_nat_dec_eq(v_j_98_, v___x_119_);
if (v___x_120_ == 0)
{
lean_dec(v_s_106_);
lean_dec(v_neg_103_);
return v_zero_99_;
}
else
{
lean_object* v___x_121_; 
lean_dec(v_zero_99_);
v___x_121_ = lean_apply_1(v_neg_103_, v_s_106_);
return v___x_121_;
}
}
else
{
lean_object* v___x_122_; 
lean_dec(v_s_106_);
lean_dec(v_neg_103_);
lean_dec(v_zero_99_);
v___x_122_ = lean_apply_2(v_div_102_, v_D_96_, v_two_100_);
return v___x_122_;
}
}
}
else
{
uint8_t v___x_123_; 
v___x_123_ = lean_nat_dec_eq(v_j_98_, v___x_107_);
if (v___x_123_ == 0)
{
lean_object* v___x_124_; uint8_t v___x_125_; 
lean_dec(v_div_102_);
lean_dec(v_two_100_);
lean_dec(v_D_96_);
v___x_124_ = lean_unsigned_to_nat(2u);
v___x_125_ = lean_nat_dec_eq(v_j_98_, v___x_124_);
if (v___x_125_ == 0)
{
lean_dec(v_s_106_);
lean_dec(v_neg_103_);
return v_zero_99_;
}
else
{
lean_object* v___x_126_; 
lean_dec(v_zero_99_);
v___x_126_ = lean_apply_1(v_neg_103_, v_s_106_);
return v___x_126_;
}
}
else
{
lean_object* v___x_127_; lean_object* v___x_128_; 
lean_dec(v_s_106_);
lean_dec(v_zero_99_);
v___x_127_ = lean_apply_2(v_div_102_, v_D_96_, v_two_100_);
v___x_128_ = lean_apply_1(v_neg_103_, v___x_127_);
return v___x_128_;
}
}
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_ham3___boxed(lean_object* v_F_129_, lean_object* v_t_130_, lean_object* v_U_131_, lean_object* v_D_132_, lean_object* v_i_133_, lean_object* v_j_134_){
_start:
{
lean_object* v_res_135_; 
v_res_135_ = lp_levy_x2dcharacterization_BrayAli_ham3(v_F_129_, v_t_130_, v_U_131_, v_D_132_, v_i_133_, v_j_134_);
lean_dec(v_j_134_);
lean_dec(v_i_133_);
lean_dec(v_U_131_);
return v_res_135_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_secularPoly(lean_object* v_F_136_, lean_object* v_t_137_, lean_object* v_U_138_, lean_object* v_D_139_, lean_object* v_E_140_){
_start:
{
lean_object* v_four_141_; lean_object* v_sub_142_; lean_object* v_mul_143_; lean_object* v_div_144_; lean_object* v___x_145_; lean_object* v___x_146_; lean_object* v___x_147_; lean_object* v___x_148_; lean_object* v___x_149_; lean_object* v___x_150_; lean_object* v___x_151_; lean_object* v___x_152_; lean_object* v___x_153_; lean_object* v___x_154_; 
v_four_141_ = lean_ctor_get(v_F_136_, 3);
lean_inc_n(v_four_141_, 2);
v_sub_142_ = lean_ctor_get(v_F_136_, 5);
lean_inc_n(v_sub_142_, 3);
v_mul_143_ = lean_ctor_get(v_F_136_, 6);
lean_inc_n(v_mul_143_, 6);
v_div_144_ = lean_ctor_get(v_F_136_, 7);
lean_inc(v_div_144_);
lean_dec_ref(v_F_136_);
lean_inc_n(v_E_140_, 3);
v___x_145_ = lean_apply_2(v_sub_142_, v_E_140_, v_U_138_);
v___x_146_ = lean_apply_2(v_mul_143_, v_E_140_, v_E_140_);
lean_inc(v_D_139_);
v___x_147_ = lean_apply_2(v_mul_143_, v_D_139_, v_D_139_);
v___x_148_ = lean_apply_2(v_div_144_, v___x_147_, v_four_141_);
v___x_149_ = lean_apply_2(v_sub_142_, v___x_146_, v___x_148_);
v___x_150_ = lean_apply_2(v_mul_143_, v___x_145_, v___x_149_);
lean_inc(v_t_137_);
v___x_151_ = lean_apply_2(v_mul_143_, v_t_137_, v_t_137_);
v___x_152_ = lean_apply_2(v_mul_143_, v_four_141_, v___x_151_);
v___x_153_ = lean_apply_2(v_mul_143_, v___x_152_, v_E_140_);
v___x_154_ = lean_apply_2(v_sub_142_, v___x_150_, v___x_153_);
return v___x_154_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_eps__exact__of__energy(lean_object* v_F_155_, lean_object* v_D_156_, lean_object* v_E_157_){
_start:
{
lean_object* v_two_158_; lean_object* v_add_159_; lean_object* v_sub_160_; lean_object* v_div_161_; lean_object* v___x_162_; lean_object* v___x_163_; lean_object* v___x_164_; lean_object* v___x_165_; 
v_two_158_ = lean_ctor_get(v_F_155_, 2);
lean_inc(v_two_158_);
v_add_159_ = lean_ctor_get(v_F_155_, 4);
lean_inc(v_add_159_);
v_sub_160_ = lean_ctor_get(v_F_155_, 5);
lean_inc(v_sub_160_);
v_div_161_ = lean_ctor_get(v_F_155_, 7);
lean_inc_n(v_div_161_, 2);
lean_dec_ref(v_F_155_);
v___x_162_ = lean_apply_2(v_div_161_, v_D_156_, v_two_158_);
lean_inc(v___x_162_);
lean_inc(v_E_157_);
v___x_163_ = lean_apply_2(v_add_159_, v_E_157_, v___x_162_);
v___x_164_ = lean_apply_2(v_sub_160_, v_E_157_, v___x_162_);
v___x_165_ = lean_apply_2(v_div_161_, v___x_163_, v___x_164_);
return v___x_165_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_p__rare__secular__of__energy(lean_object* v_F_166_, lean_object* v_t_167_, lean_object* v_D_168_, lean_object* v_E_169_){
_start:
{
lean_object* v_one_170_; lean_object* v_two_171_; lean_object* v_add_172_; lean_object* v_mul_173_; lean_object* v_div_174_; lean_object* v_eps_175_; lean_object* v___x_176_; lean_object* v_ed_177_; lean_object* v___x_178_; lean_object* v___x_179_; lean_object* v___x_180_; lean_object* v_bright_181_; lean_object* v___x_182_; lean_object* v___x_183_; lean_object* v___x_184_; lean_object* v___x_185_; 
v_one_170_ = lean_ctor_get(v_F_166_, 1);
lean_inc(v_one_170_);
v_two_171_ = lean_ctor_get(v_F_166_, 2);
lean_inc_n(v_two_171_, 2);
v_add_172_ = lean_ctor_get(v_F_166_, 4);
lean_inc_n(v_add_172_, 3);
v_mul_173_ = lean_ctor_get(v_F_166_, 6);
lean_inc_n(v_mul_173_, 4);
v_div_174_ = lean_ctor_get(v_F_166_, 7);
lean_inc_n(v_div_174_, 3);
lean_inc(v_E_169_);
lean_inc(v_D_168_);
v_eps_175_ = lp_levy_x2dcharacterization_BrayAli_eps__exact__of__energy(v_F_166_, v_D_168_, v_E_169_);
v___x_176_ = lean_apply_2(v_div_174_, v_D_168_, v_two_171_);
v_ed_177_ = lean_apply_2(v_add_172_, v_E_169_, v___x_176_);
lean_inc(v_ed_177_);
v___x_178_ = lean_apply_2(v_mul_173_, v_ed_177_, v_ed_177_);
lean_inc(v_t_167_);
v___x_179_ = lean_apply_2(v_mul_173_, v_t_167_, v_t_167_);
v___x_180_ = lean_apply_2(v_mul_173_, v_two_171_, v___x_179_);
v_bright_181_ = lean_apply_2(v_div_174_, v___x_178_, v___x_180_);
lean_inc(v_eps_175_);
v___x_182_ = lean_apply_2(v_mul_173_, v_eps_175_, v_eps_175_);
lean_inc(v___x_182_);
v___x_183_ = lean_apply_2(v_add_172_, v_one_170_, v___x_182_);
v___x_184_ = lean_apply_2(v_add_172_, v___x_183_, v_bright_181_);
v___x_185_ = lean_apply_2(v_div_174_, v___x_182_, v___x_184_);
return v___x_185_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_kappa__paper(lean_object* v_F_186_, lean_object* v_t_187_, lean_object* v_U_188_, lean_object* v_D_189_){
_start:
{
lean_object* v_two_190_; lean_object* v_mul_191_; lean_object* v_div_192_; lean_object* v___x_193_; lean_object* v___x_194_; lean_object* v___x_195_; lean_object* v___x_196_; 
v_two_190_ = lean_ctor_get(v_F_186_, 2);
lean_inc(v_two_190_);
v_mul_191_ = lean_ctor_get(v_F_186_, 6);
lean_inc_n(v_mul_191_, 3);
v_div_192_ = lean_ctor_get(v_F_186_, 7);
lean_inc(v_div_192_);
lean_dec_ref(v_F_186_);
lean_inc(v_t_187_);
v___x_193_ = lean_apply_2(v_mul_191_, v_t_187_, v_t_187_);
v___x_194_ = lean_apply_2(v_mul_191_, v_two_190_, v___x_193_);
v___x_195_ = lean_apply_2(v_mul_191_, v_U_188_, v_D_189_);
v___x_196_ = lean_apply_2(v_div_192_, v___x_194_, v___x_195_);
return v___x_196_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_kappa__onshell(lean_object* v_F_197_, lean_object* v_t_198_, lean_object* v_U_199_, lean_object* v_D_200_){
_start:
{
lean_object* v_two_201_; lean_object* v_add_202_; lean_object* v_mul_203_; lean_object* v_div_204_; lean_object* v___x_205_; lean_object* v___x_206_; lean_object* v___x_207_; lean_object* v___x_208_; lean_object* v___x_209_; lean_object* v___x_210_; 
v_two_201_ = lean_ctor_get(v_F_197_, 2);
lean_inc_n(v_two_201_, 2);
v_add_202_ = lean_ctor_get(v_F_197_, 4);
lean_inc(v_add_202_);
v_mul_203_ = lean_ctor_get(v_F_197_, 6);
lean_inc_n(v_mul_203_, 3);
v_div_204_ = lean_ctor_get(v_F_197_, 7);
lean_inc_n(v_div_204_, 2);
lean_dec_ref(v_F_197_);
lean_inc(v_t_198_);
v___x_205_ = lean_apply_2(v_mul_203_, v_t_198_, v_t_198_);
v___x_206_ = lean_apply_2(v_mul_203_, v_two_201_, v___x_205_);
lean_inc(v_D_200_);
v___x_207_ = lean_apply_2(v_div_204_, v_D_200_, v_two_201_);
v___x_208_ = lean_apply_2(v_add_202_, v_U_199_, v___x_207_);
v___x_209_ = lean_apply_2(v_mul_203_, v___x_208_, v_D_200_);
v___x_210_ = lean_apply_2(v_div_204_, v___x_206_, v___x_209_);
return v___x_210_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_eps__bounds(lean_object* v_F_211_, lean_object* v_t_212_, lean_object* v_U_213_, lean_object* v_D_214_){
_start:
{
lean_object* v_one_215_; lean_object* v_two_216_; lean_object* v_add_217_; lean_object* v_sub_218_; lean_object* v_mul_219_; lean_object* v_div_220_; lean_object* v_k_221_; lean_object* v___x_222_; lean_object* v___x_223_; lean_object* v_m_224_; lean_object* v___x_225_; lean_object* v___x_226_; lean_object* v___x_227_; lean_object* v___x_228_; lean_object* v___x_229_; lean_object* v___x_230_; lean_object* v___x_231_; lean_object* v_lo_232_; lean_object* v_hi_233_; lean_object* v___x_234_; 
v_one_215_ = lean_ctor_get(v_F_211_, 1);
lean_inc(v_one_215_);
v_two_216_ = lean_ctor_get(v_F_211_, 2);
lean_inc_n(v_two_216_, 2);
v_add_217_ = lean_ctor_get(v_F_211_, 4);
lean_inc_n(v_add_217_, 3);
v_sub_218_ = lean_ctor_get(v_F_211_, 5);
lean_inc(v_sub_218_);
v_mul_219_ = lean_ctor_get(v_F_211_, 6);
lean_inc_n(v_mul_219_, 4);
v_div_220_ = lean_ctor_get(v_F_211_, 7);
lean_inc_n(v_div_220_, 4);
lean_inc_n(v_D_214_, 3);
lean_inc(v_U_213_);
lean_inc_n(v_t_212_, 2);
v_k_221_ = lp_levy_x2dcharacterization_BrayAli_kappa__onshell(v_F_211_, v_t_212_, v_U_213_, v_D_214_);
lean_inc_n(v_k_221_, 2);
v___x_222_ = lean_apply_2(v_mul_219_, v_k_221_, v_D_214_);
v___x_223_ = lean_apply_2(v_sub_218_, v_one_215_, v_k_221_);
lean_inc(v___x_223_);
v_m_224_ = lean_apply_2(v_div_220_, v___x_222_, v___x_223_);
v___x_225_ = lean_apply_2(v_mul_219_, v_t_212_, v_t_212_);
v___x_226_ = lean_apply_2(v_mul_219_, v_two_216_, v___x_225_);
v___x_227_ = lean_apply_2(v_div_220_, v_D_214_, v_two_216_);
v___x_228_ = lean_apply_2(v_add_217_, v_U_213_, v___x_227_);
lean_inc(v_m_224_);
v___x_229_ = lean_apply_2(v_add_217_, v___x_228_, v_m_224_);
v___x_230_ = lean_apply_2(v_add_217_, v_D_214_, v_m_224_);
v___x_231_ = lean_apply_2(v_mul_219_, v___x_229_, v___x_230_);
v_lo_232_ = lean_apply_2(v_div_220_, v___x_226_, v___x_231_);
v_hi_233_ = lean_apply_2(v_div_220_, v_k_221_, v___x_223_);
v___x_234_ = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(v___x_234_, 0, v_lo_232_);
lean_ctor_set(v___x_234_, 1, v_hi_233_);
return v___x_234_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_lindblad__prob__factor(lean_object* v_F_235_, lean_object* v_factor_236_, lean_object* v_p__rare_237_){
_start:
{
lean_object* v_mul_238_; lean_object* v___x_239_; 
v_mul_238_ = lean_ctor_get(v_F_235_, 6);
lean_inc(v_mul_238_);
lean_dec_ref(v_F_235_);
v___x_239_ = lean_apply_2(v_mul_238_, v_factor_236_, v_p__rare_237_);
return v___x_239_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Add___redArg(lean_object* v_C_240_, lean_object* v_A_241_, lean_object* v_B_242_){
_start:
{
lean_object* v_add_243_; lean_object* v_m00_244_; lean_object* v_m01_245_; lean_object* v_m10_246_; lean_object* v_m11_247_; lean_object* v_m00_248_; lean_object* v_m01_249_; lean_object* v_m10_250_; lean_object* v_m11_251_; lean_object* v___x_253_; uint8_t v_isShared_254_; uint8_t v_isSharedCheck_262_; 
v_add_243_ = lean_ctor_get(v_C_240_, 2);
lean_inc(v_add_243_);
lean_dec_ref(v_C_240_);
v_m00_244_ = lean_ctor_get(v_A_241_, 0);
lean_inc(v_m00_244_);
v_m01_245_ = lean_ctor_get(v_A_241_, 1);
lean_inc(v_m01_245_);
v_m10_246_ = lean_ctor_get(v_A_241_, 2);
lean_inc(v_m10_246_);
v_m11_247_ = lean_ctor_get(v_A_241_, 3);
lean_inc(v_m11_247_);
lean_dec_ref(v_A_241_);
v_m00_248_ = lean_ctor_get(v_B_242_, 0);
v_m01_249_ = lean_ctor_get(v_B_242_, 1);
v_m10_250_ = lean_ctor_get(v_B_242_, 2);
v_m11_251_ = lean_ctor_get(v_B_242_, 3);
v_isSharedCheck_262_ = !lean_is_exclusive(v_B_242_);
if (v_isSharedCheck_262_ == 0)
{
v___x_253_ = v_B_242_;
v_isShared_254_ = v_isSharedCheck_262_;
goto v_resetjp_252_;
}
else
{
lean_inc(v_m11_251_);
lean_inc(v_m10_250_);
lean_inc(v_m01_249_);
lean_inc(v_m00_248_);
lean_dec(v_B_242_);
v___x_253_ = lean_box(0);
v_isShared_254_ = v_isSharedCheck_262_;
goto v_resetjp_252_;
}
v_resetjp_252_:
{
lean_object* v___x_255_; lean_object* v___x_256_; lean_object* v___x_257_; lean_object* v___x_258_; lean_object* v___x_260_; 
lean_inc_n(v_add_243_, 3);
v___x_255_ = lean_apply_2(v_add_243_, v_m00_244_, v_m00_248_);
v___x_256_ = lean_apply_2(v_add_243_, v_m01_245_, v_m01_249_);
v___x_257_ = lean_apply_2(v_add_243_, v_m10_246_, v_m10_250_);
v___x_258_ = lean_apply_2(v_add_243_, v_m11_247_, v_m11_251_);
if (v_isShared_254_ == 0)
{
lean_ctor_set(v___x_253_, 3, v___x_258_);
lean_ctor_set(v___x_253_, 2, v___x_257_);
lean_ctor_set(v___x_253_, 1, v___x_256_);
lean_ctor_set(v___x_253_, 0, v___x_255_);
v___x_260_ = v___x_253_;
goto v_reusejp_259_;
}
else
{
lean_object* v_reuseFailAlloc_261_; 
v_reuseFailAlloc_261_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v_reuseFailAlloc_261_, 0, v___x_255_);
lean_ctor_set(v_reuseFailAlloc_261_, 1, v___x_256_);
lean_ctor_set(v_reuseFailAlloc_261_, 2, v___x_257_);
lean_ctor_set(v_reuseFailAlloc_261_, 3, v___x_258_);
v___x_260_ = v_reuseFailAlloc_261_;
goto v_reusejp_259_;
}
v_reusejp_259_:
{
return v___x_260_;
}
}
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Add(lean_object* v_F_263_, lean_object* v_C_264_, lean_object* v_A_265_, lean_object* v_B_266_){
_start:
{
lean_object* v___x_267_; 
v___x_267_ = lp_levy_x2dcharacterization_BrayAli_mat2Add___redArg(v_C_264_, v_A_265_, v_B_266_);
return v___x_267_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Add___boxed(lean_object* v_F_268_, lean_object* v_C_269_, lean_object* v_A_270_, lean_object* v_B_271_){
_start:
{
lean_object* v_res_272_; 
v_res_272_ = lp_levy_x2dcharacterization_BrayAli_mat2Add(v_F_268_, v_C_269_, v_A_270_, v_B_271_);
lean_dec_ref(v_F_268_);
return v_res_272_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Sub___redArg(lean_object* v_C_273_, lean_object* v_A_274_, lean_object* v_B_275_){
_start:
{
lean_object* v_sub_276_; lean_object* v_m00_277_; lean_object* v_m01_278_; lean_object* v_m10_279_; lean_object* v_m11_280_; lean_object* v_m00_281_; lean_object* v_m01_282_; lean_object* v_m10_283_; lean_object* v_m11_284_; lean_object* v___x_286_; uint8_t v_isShared_287_; uint8_t v_isSharedCheck_295_; 
v_sub_276_ = lean_ctor_get(v_C_273_, 3);
lean_inc(v_sub_276_);
lean_dec_ref(v_C_273_);
v_m00_277_ = lean_ctor_get(v_A_274_, 0);
lean_inc(v_m00_277_);
v_m01_278_ = lean_ctor_get(v_A_274_, 1);
lean_inc(v_m01_278_);
v_m10_279_ = lean_ctor_get(v_A_274_, 2);
lean_inc(v_m10_279_);
v_m11_280_ = lean_ctor_get(v_A_274_, 3);
lean_inc(v_m11_280_);
lean_dec_ref(v_A_274_);
v_m00_281_ = lean_ctor_get(v_B_275_, 0);
v_m01_282_ = lean_ctor_get(v_B_275_, 1);
v_m10_283_ = lean_ctor_get(v_B_275_, 2);
v_m11_284_ = lean_ctor_get(v_B_275_, 3);
v_isSharedCheck_295_ = !lean_is_exclusive(v_B_275_);
if (v_isSharedCheck_295_ == 0)
{
v___x_286_ = v_B_275_;
v_isShared_287_ = v_isSharedCheck_295_;
goto v_resetjp_285_;
}
else
{
lean_inc(v_m11_284_);
lean_inc(v_m10_283_);
lean_inc(v_m01_282_);
lean_inc(v_m00_281_);
lean_dec(v_B_275_);
v___x_286_ = lean_box(0);
v_isShared_287_ = v_isSharedCheck_295_;
goto v_resetjp_285_;
}
v_resetjp_285_:
{
lean_object* v___x_288_; lean_object* v___x_289_; lean_object* v___x_290_; lean_object* v___x_291_; lean_object* v___x_293_; 
lean_inc_n(v_sub_276_, 3);
v___x_288_ = lean_apply_2(v_sub_276_, v_m00_277_, v_m00_281_);
v___x_289_ = lean_apply_2(v_sub_276_, v_m01_278_, v_m01_282_);
v___x_290_ = lean_apply_2(v_sub_276_, v_m10_279_, v_m10_283_);
v___x_291_ = lean_apply_2(v_sub_276_, v_m11_280_, v_m11_284_);
if (v_isShared_287_ == 0)
{
lean_ctor_set(v___x_286_, 3, v___x_291_);
lean_ctor_set(v___x_286_, 2, v___x_290_);
lean_ctor_set(v___x_286_, 1, v___x_289_);
lean_ctor_set(v___x_286_, 0, v___x_288_);
v___x_293_ = v___x_286_;
goto v_reusejp_292_;
}
else
{
lean_object* v_reuseFailAlloc_294_; 
v_reuseFailAlloc_294_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v_reuseFailAlloc_294_, 0, v___x_288_);
lean_ctor_set(v_reuseFailAlloc_294_, 1, v___x_289_);
lean_ctor_set(v_reuseFailAlloc_294_, 2, v___x_290_);
lean_ctor_set(v_reuseFailAlloc_294_, 3, v___x_291_);
v___x_293_ = v_reuseFailAlloc_294_;
goto v_reusejp_292_;
}
v_reusejp_292_:
{
return v___x_293_;
}
}
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Sub(lean_object* v_F_296_, lean_object* v_C_297_, lean_object* v_A_298_, lean_object* v_B_299_){
_start:
{
lean_object* v___x_300_; 
v___x_300_ = lp_levy_x2dcharacterization_BrayAli_mat2Sub___redArg(v_C_297_, v_A_298_, v_B_299_);
return v___x_300_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Sub___boxed(lean_object* v_F_301_, lean_object* v_C_302_, lean_object* v_A_303_, lean_object* v_B_304_){
_start:
{
lean_object* v_res_305_; 
v_res_305_ = lp_levy_x2dcharacterization_BrayAli_mat2Sub(v_F_301_, v_C_302_, v_A_303_, v_B_304_);
lean_dec_ref(v_F_301_);
return v_res_305_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Smul___redArg(lean_object* v_C_306_, lean_object* v_c_307_, lean_object* v_A_308_){
_start:
{
lean_object* v_mul_309_; lean_object* v_m00_310_; lean_object* v_m01_311_; lean_object* v_m10_312_; lean_object* v_m11_313_; lean_object* v___x_315_; uint8_t v_isShared_316_; uint8_t v_isSharedCheck_324_; 
v_mul_309_ = lean_ctor_get(v_C_306_, 4);
lean_inc(v_mul_309_);
lean_dec_ref(v_C_306_);
v_m00_310_ = lean_ctor_get(v_A_308_, 0);
v_m01_311_ = lean_ctor_get(v_A_308_, 1);
v_m10_312_ = lean_ctor_get(v_A_308_, 2);
v_m11_313_ = lean_ctor_get(v_A_308_, 3);
v_isSharedCheck_324_ = !lean_is_exclusive(v_A_308_);
if (v_isSharedCheck_324_ == 0)
{
v___x_315_ = v_A_308_;
v_isShared_316_ = v_isSharedCheck_324_;
goto v_resetjp_314_;
}
else
{
lean_inc(v_m11_313_);
lean_inc(v_m10_312_);
lean_inc(v_m01_311_);
lean_inc(v_m00_310_);
lean_dec(v_A_308_);
v___x_315_ = lean_box(0);
v_isShared_316_ = v_isSharedCheck_324_;
goto v_resetjp_314_;
}
v_resetjp_314_:
{
lean_object* v___x_317_; lean_object* v___x_318_; lean_object* v___x_319_; lean_object* v___x_320_; lean_object* v___x_322_; 
lean_inc_n(v_mul_309_, 3);
lean_inc_n(v_c_307_, 3);
v___x_317_ = lean_apply_2(v_mul_309_, v_c_307_, v_m00_310_);
v___x_318_ = lean_apply_2(v_mul_309_, v_c_307_, v_m01_311_);
v___x_319_ = lean_apply_2(v_mul_309_, v_c_307_, v_m10_312_);
v___x_320_ = lean_apply_2(v_mul_309_, v_c_307_, v_m11_313_);
if (v_isShared_316_ == 0)
{
lean_ctor_set(v___x_315_, 3, v___x_320_);
lean_ctor_set(v___x_315_, 2, v___x_319_);
lean_ctor_set(v___x_315_, 1, v___x_318_);
lean_ctor_set(v___x_315_, 0, v___x_317_);
v___x_322_ = v___x_315_;
goto v_reusejp_321_;
}
else
{
lean_object* v_reuseFailAlloc_323_; 
v_reuseFailAlloc_323_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v_reuseFailAlloc_323_, 0, v___x_317_);
lean_ctor_set(v_reuseFailAlloc_323_, 1, v___x_318_);
lean_ctor_set(v_reuseFailAlloc_323_, 2, v___x_319_);
lean_ctor_set(v_reuseFailAlloc_323_, 3, v___x_320_);
v___x_322_ = v_reuseFailAlloc_323_;
goto v_reusejp_321_;
}
v_reusejp_321_:
{
return v___x_322_;
}
}
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Smul(lean_object* v_F_325_, lean_object* v_C_326_, lean_object* v_c_327_, lean_object* v_A_328_){
_start:
{
lean_object* v___x_329_; 
v___x_329_ = lp_levy_x2dcharacterization_BrayAli_mat2Smul___redArg(v_C_326_, v_c_327_, v_A_328_);
return v___x_329_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Smul___boxed(lean_object* v_F_330_, lean_object* v_C_331_, lean_object* v_c_332_, lean_object* v_A_333_){
_start:
{
lean_object* v_res_334_; 
v_res_334_ = lp_levy_x2dcharacterization_BrayAli_mat2Smul(v_F_330_, v_C_331_, v_c_332_, v_A_333_);
lean_dec_ref(v_F_330_);
return v_res_334_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Mul___redArg(lean_object* v_C_335_, lean_object* v_A_336_, lean_object* v_B_337_){
_start:
{
lean_object* v_add_338_; lean_object* v_mul_339_; lean_object* v_m00_340_; lean_object* v_m01_341_; lean_object* v_m10_342_; lean_object* v_m11_343_; lean_object* v_m00_344_; lean_object* v_m01_345_; lean_object* v_m10_346_; lean_object* v_m11_347_; lean_object* v___x_349_; uint8_t v_isShared_350_; uint8_t v_isSharedCheck_366_; 
v_add_338_ = lean_ctor_get(v_C_335_, 2);
lean_inc(v_add_338_);
v_mul_339_ = lean_ctor_get(v_C_335_, 4);
lean_inc(v_mul_339_);
lean_dec_ref(v_C_335_);
v_m00_340_ = lean_ctor_get(v_A_336_, 0);
lean_inc(v_m00_340_);
v_m01_341_ = lean_ctor_get(v_A_336_, 1);
lean_inc(v_m01_341_);
v_m10_342_ = lean_ctor_get(v_A_336_, 2);
lean_inc(v_m10_342_);
v_m11_343_ = lean_ctor_get(v_A_336_, 3);
lean_inc(v_m11_343_);
lean_dec_ref(v_A_336_);
v_m00_344_ = lean_ctor_get(v_B_337_, 0);
v_m01_345_ = lean_ctor_get(v_B_337_, 1);
v_m10_346_ = lean_ctor_get(v_B_337_, 2);
v_m11_347_ = lean_ctor_get(v_B_337_, 3);
v_isSharedCheck_366_ = !lean_is_exclusive(v_B_337_);
if (v_isSharedCheck_366_ == 0)
{
v___x_349_ = v_B_337_;
v_isShared_350_ = v_isSharedCheck_366_;
goto v_resetjp_348_;
}
else
{
lean_inc(v_m11_347_);
lean_inc(v_m10_346_);
lean_inc(v_m01_345_);
lean_inc(v_m00_344_);
lean_dec(v_B_337_);
v___x_349_ = lean_box(0);
v_isShared_350_ = v_isSharedCheck_366_;
goto v_resetjp_348_;
}
v_resetjp_348_:
{
lean_object* v___x_351_; lean_object* v___x_352_; lean_object* v___x_353_; lean_object* v___x_354_; lean_object* v___x_355_; lean_object* v___x_356_; lean_object* v___x_357_; lean_object* v___x_358_; lean_object* v___x_359_; lean_object* v___x_360_; lean_object* v___x_361_; lean_object* v___x_362_; lean_object* v___x_364_; 
lean_inc_n(v_mul_339_, 7);
lean_inc(v_m00_344_);
lean_inc(v_m00_340_);
v___x_351_ = lean_apply_2(v_mul_339_, v_m00_340_, v_m00_344_);
lean_inc(v_m10_346_);
lean_inc(v_m01_341_);
v___x_352_ = lean_apply_2(v_mul_339_, v_m01_341_, v_m10_346_);
lean_inc_n(v_add_338_, 3);
v___x_353_ = lean_apply_2(v_add_338_, v___x_351_, v___x_352_);
lean_inc(v_m01_345_);
v___x_354_ = lean_apply_2(v_mul_339_, v_m00_340_, v_m01_345_);
lean_inc(v_m11_347_);
v___x_355_ = lean_apply_2(v_mul_339_, v_m01_341_, v_m11_347_);
v___x_356_ = lean_apply_2(v_add_338_, v___x_354_, v___x_355_);
lean_inc(v_m10_342_);
v___x_357_ = lean_apply_2(v_mul_339_, v_m10_342_, v_m00_344_);
lean_inc(v_m11_343_);
v___x_358_ = lean_apply_2(v_mul_339_, v_m11_343_, v_m10_346_);
v___x_359_ = lean_apply_2(v_add_338_, v___x_357_, v___x_358_);
v___x_360_ = lean_apply_2(v_mul_339_, v_m10_342_, v_m01_345_);
v___x_361_ = lean_apply_2(v_mul_339_, v_m11_343_, v_m11_347_);
v___x_362_ = lean_apply_2(v_add_338_, v___x_360_, v___x_361_);
if (v_isShared_350_ == 0)
{
lean_ctor_set(v___x_349_, 3, v___x_362_);
lean_ctor_set(v___x_349_, 2, v___x_359_);
lean_ctor_set(v___x_349_, 1, v___x_356_);
lean_ctor_set(v___x_349_, 0, v___x_353_);
v___x_364_ = v___x_349_;
goto v_reusejp_363_;
}
else
{
lean_object* v_reuseFailAlloc_365_; 
v_reuseFailAlloc_365_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v_reuseFailAlloc_365_, 0, v___x_353_);
lean_ctor_set(v_reuseFailAlloc_365_, 1, v___x_356_);
lean_ctor_set(v_reuseFailAlloc_365_, 2, v___x_359_);
lean_ctor_set(v_reuseFailAlloc_365_, 3, v___x_362_);
v___x_364_ = v_reuseFailAlloc_365_;
goto v_reusejp_363_;
}
v_reusejp_363_:
{
return v___x_364_;
}
}
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Mul(lean_object* v_F_367_, lean_object* v_C_368_, lean_object* v_A_369_, lean_object* v_B_370_){
_start:
{
lean_object* v___x_371_; 
v___x_371_ = lp_levy_x2dcharacterization_BrayAli_mat2Mul___redArg(v_C_368_, v_A_369_, v_B_370_);
return v___x_371_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Mul___boxed(lean_object* v_F_372_, lean_object* v_C_373_, lean_object* v_A_374_, lean_object* v_B_375_){
_start:
{
lean_object* v_res_376_; 
v_res_376_ = lp_levy_x2dcharacterization_BrayAli_mat2Mul(v_F_372_, v_C_373_, v_A_374_, v_B_375_);
lean_dec_ref(v_F_372_);
return v_res_376_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Trace___redArg(lean_object* v_C_377_, lean_object* v_A_378_){
_start:
{
lean_object* v_add_379_; lean_object* v_m00_380_; lean_object* v_m11_381_; lean_object* v___x_382_; 
v_add_379_ = lean_ctor_get(v_C_377_, 2);
lean_inc(v_add_379_);
lean_dec_ref(v_C_377_);
v_m00_380_ = lean_ctor_get(v_A_378_, 0);
lean_inc(v_m00_380_);
v_m11_381_ = lean_ctor_get(v_A_378_, 3);
lean_inc(v_m11_381_);
lean_dec_ref(v_A_378_);
v___x_382_ = lean_apply_2(v_add_379_, v_m00_380_, v_m11_381_);
return v___x_382_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Trace(lean_object* v_F_383_, lean_object* v_C_384_, lean_object* v_A_385_){
_start:
{
lean_object* v___x_386_; 
v___x_386_ = lp_levy_x2dcharacterization_BrayAli_mat2Trace___redArg(v_C_384_, v_A_385_);
return v___x_386_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_mat2Trace___boxed(lean_object* v_F_387_, lean_object* v_C_388_, lean_object* v_A_389_){
_start:
{
lean_object* v_res_390_; 
v_res_390_ = lp_levy_x2dcharacterization_BrayAli_mat2Trace(v_F_387_, v_C_388_, v_A_389_);
lean_dec_ref(v_F_387_);
return v_res_390_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_SZ(lean_object* v_F_391_, lean_object* v_C_392_){
_start:
{
lean_object* v_ofReal_393_; lean_object* v_neg_394_; lean_object* v_zero_395_; lean_object* v_one_396_; lean_object* v___x_397_; lean_object* v___x_398_; lean_object* v___x_399_; lean_object* v___x_400_; 
v_ofReal_393_ = lean_ctor_get(v_C_392_, 0);
lean_inc_n(v_ofReal_393_, 2);
v_neg_394_ = lean_ctor_get(v_C_392_, 5);
lean_inc(v_neg_394_);
lean_dec_ref(v_C_392_);
v_zero_395_ = lean_ctor_get(v_F_391_, 0);
lean_inc(v_zero_395_);
v_one_396_ = lean_ctor_get(v_F_391_, 1);
lean_inc(v_one_396_);
lean_dec_ref(v_F_391_);
v___x_397_ = lean_apply_1(v_ofReal_393_, v_one_396_);
v___x_398_ = lean_apply_1(v_ofReal_393_, v_zero_395_);
lean_inc(v___x_397_);
v___x_399_ = lean_apply_1(v_neg_394_, v___x_397_);
lean_inc(v___x_398_);
v___x_400_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_400_, 0, v___x_397_);
lean_ctor_set(v___x_400_, 1, v___x_398_);
lean_ctor_set(v___x_400_, 2, v___x_398_);
lean_ctor_set(v___x_400_, 3, v___x_399_);
return v___x_400_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_SX(lean_object* v_F_401_, lean_object* v_C_402_){
_start:
{
lean_object* v_ofReal_403_; lean_object* v_zero_404_; lean_object* v_one_405_; lean_object* v___x_406_; lean_object* v___x_407_; lean_object* v___x_408_; 
v_ofReal_403_ = lean_ctor_get(v_C_402_, 0);
lean_inc_n(v_ofReal_403_, 2);
lean_dec_ref(v_C_402_);
v_zero_404_ = lean_ctor_get(v_F_401_, 0);
lean_inc(v_zero_404_);
v_one_405_ = lean_ctor_get(v_F_401_, 1);
lean_inc(v_one_405_);
lean_dec_ref(v_F_401_);
v___x_406_ = lean_apply_1(v_ofReal_403_, v_zero_404_);
v___x_407_ = lean_apply_1(v_ofReal_403_, v_one_405_);
lean_inc(v___x_407_);
lean_inc(v___x_406_);
v___x_408_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_408_, 0, v___x_406_);
lean_ctor_set(v___x_408_, 1, v___x_407_);
lean_ctor_set(v___x_408_, 2, v___x_407_);
lean_ctor_set(v___x_408_, 3, v___x_406_);
return v___x_408_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_I2(lean_object* v_F_409_, lean_object* v_C_410_){
_start:
{
lean_object* v_ofReal_411_; lean_object* v_zero_412_; lean_object* v_one_413_; lean_object* v___x_414_; lean_object* v___x_415_; lean_object* v___x_416_; 
v_ofReal_411_ = lean_ctor_get(v_C_410_, 0);
lean_inc_n(v_ofReal_411_, 2);
lean_dec_ref(v_C_410_);
v_zero_412_ = lean_ctor_get(v_F_409_, 0);
lean_inc(v_zero_412_);
v_one_413_ = lean_ctor_get(v_F_409_, 1);
lean_inc(v_one_413_);
lean_dec_ref(v_F_409_);
v___x_414_ = lean_apply_1(v_ofReal_411_, v_one_413_);
v___x_415_ = lean_apply_1(v_ofReal_411_, v_zero_412_);
lean_inc(v___x_415_);
lean_inc(v___x_414_);
v___x_416_ = lean_alloc_ctor(0, 4, 0);
lean_ctor_set(v___x_416_, 0, v___x_414_);
lean_ctor_set(v___x_416_, 1, v___x_415_);
lean_ctor_set(v___x_416_, 2, v___x_415_);
lean_ctor_set(v___x_416_, 3, v___x_414_);
return v___x_416_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_effective__h2(lean_object* v_F_417_, lean_object* v_C_418_, lean_object* v_t_419_, lean_object* v_U_420_, lean_object* v_D_421_){
_start:
{
lean_object* v_two_422_; lean_object* v_add_423_; lean_object* v_mul_424_; lean_object* v_div_425_; lean_object* v_neg_426_; lean_object* v___x_427_; lean_object* v___x_428_; lean_object* v_ofReal_429_; lean_object* v___x_430_; lean_object* v___x_431_; lean_object* v_J_432_; lean_object* v___x_433_; lean_object* v___x_434_; lean_object* v___x_435_; lean_object* v___x_436_; lean_object* v___x_437_; lean_object* v___x_438_; lean_object* v___x_439_; lean_object* v___x_440_; 
v_two_422_ = lean_ctor_get(v_F_417_, 2);
v_add_423_ = lean_ctor_get(v_F_417_, 4);
v_mul_424_ = lean_ctor_get(v_F_417_, 6);
v_div_425_ = lean_ctor_get(v_F_417_, 7);
v_neg_426_ = lean_ctor_get(v_F_417_, 8);
lean_inc_n(v_mul_424_, 2);
lean_inc(v_t_419_);
v___x_427_ = lean_apply_2(v_mul_424_, v_t_419_, v_t_419_);
lean_inc_n(v_two_422_, 2);
v___x_428_ = lean_apply_2(v_mul_424_, v_two_422_, v___x_427_);
v_ofReal_429_ = lean_ctor_get(v_C_418_, 0);
lean_inc_n(v_div_425_, 2);
v___x_430_ = lean_apply_2(v_div_425_, v_D_421_, v_two_422_);
lean_inc(v_add_423_);
lean_inc(v___x_430_);
v___x_431_ = lean_apply_2(v_add_423_, v_U_420_, v___x_430_);
v_J_432_ = lean_apply_2(v_div_425_, v___x_428_, v___x_431_);
lean_inc(v_neg_426_);
v___x_433_ = lean_apply_1(v_neg_426_, v___x_430_);
lean_inc_n(v_ofReal_429_, 2);
v___x_434_ = lean_apply_1(v_ofReal_429_, v___x_433_);
lean_inc_ref_n(v_C_418_, 4);
lean_inc_ref(v_F_417_);
v___x_435_ = lp_levy_x2dcharacterization_BrayAli_SZ(v_F_417_, v_C_418_);
v___x_436_ = lp_levy_x2dcharacterization_BrayAli_mat2Smul___redArg(v_C_418_, v___x_434_, v___x_435_);
v___x_437_ = lean_apply_1(v_ofReal_429_, v_J_432_);
v___x_438_ = lp_levy_x2dcharacterization_BrayAli_SX(v_F_417_, v_C_418_);
v___x_439_ = lp_levy_x2dcharacterization_BrayAli_mat2Smul___redArg(v_C_418_, v___x_437_, v___x_438_);
v___x_440_ = lp_levy_x2dcharacterization_BrayAli_mat2Sub___redArg(v_C_418_, v___x_436_, v___x_439_);
return v___x_440_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_lindblad__rhs(lean_object* v_F_441_, lean_object* v_C_442_, lean_object* v_H_443_, lean_object* v_gamma_444_, lean_object* v_rho_445_){
_start:
{
lean_object* v___x_446_; lean_object* v___x_447_; lean_object* v_comm_448_; lean_object* v___x_449_; lean_object* v___x_450_; lean_object* v_ofReal_451_; lean_object* v_iUnit_452_; lean_object* v_neg_453_; lean_object* v___x_454_; lean_object* v_diss_455_; lean_object* v___x_456_; lean_object* v___x_457_; lean_object* v___x_458_; lean_object* v___x_459_; lean_object* v___x_460_; 
lean_inc_ref_n(v_rho_445_, 3);
lean_inc_ref(v_H_443_);
lean_inc_ref_n(v_C_442_, 9);
v___x_446_ = lp_levy_x2dcharacterization_BrayAli_mat2Mul___redArg(v_C_442_, v_H_443_, v_rho_445_);
v___x_447_ = lp_levy_x2dcharacterization_BrayAli_mat2Mul___redArg(v_C_442_, v_rho_445_, v_H_443_);
v_comm_448_ = lp_levy_x2dcharacterization_BrayAli_mat2Sub___redArg(v_C_442_, v___x_446_, v___x_447_);
v___x_449_ = lp_levy_x2dcharacterization_BrayAli_SZ(v_F_441_, v_C_442_);
lean_inc_ref(v___x_449_);
v___x_450_ = lp_levy_x2dcharacterization_BrayAli_mat2Mul___redArg(v_C_442_, v___x_449_, v_rho_445_);
v_ofReal_451_ = lean_ctor_get(v_C_442_, 0);
v_iUnit_452_ = lean_ctor_get(v_C_442_, 1);
v_neg_453_ = lean_ctor_get(v_C_442_, 5);
v___x_454_ = lp_levy_x2dcharacterization_BrayAli_mat2Mul___redArg(v_C_442_, v___x_450_, v___x_449_);
v_diss_455_ = lp_levy_x2dcharacterization_BrayAli_mat2Sub___redArg(v_C_442_, v___x_454_, v_rho_445_);
lean_inc(v_neg_453_);
lean_inc(v_iUnit_452_);
v___x_456_ = lean_apply_1(v_neg_453_, v_iUnit_452_);
v___x_457_ = lp_levy_x2dcharacterization_BrayAli_mat2Smul___redArg(v_C_442_, v___x_456_, v_comm_448_);
lean_inc(v_ofReal_451_);
v___x_458_ = lean_apply_1(v_ofReal_451_, v_gamma_444_);
v___x_459_ = lp_levy_x2dcharacterization_BrayAli_mat2Smul___redArg(v_C_442_, v___x_458_, v_diss_455_);
v___x_460_ = lp_levy_x2dcharacterization_BrayAli_mat2Add___redArg(v_C_442_, v___x_457_, v___x_459_);
return v___x_460_;
}
}
LEAN_EXPORT lean_object* lp_levy_x2dcharacterization_BrayAli_innovation__step(lean_object* v_F_461_, lean_object* v_gamma_462_, lean_object* v_gamma__f_463_, lean_object* v_Lt_464_, lean_object* v_Lf_465_, lean_object* v_dt_466_, lean_object* v_dW_467_){
_start:
{
lean_object* v_two_468_; lean_object* v_add_469_; lean_object* v_sub_470_; lean_object* v_mul_471_; lean_object* v_sqrt_472_; lean_object* v___x_473_; lean_object* v___x_474_; lean_object* v___x_475_; lean_object* v___x_476_; lean_object* v_dY_477_; lean_object* v___x_478_; lean_object* v___x_479_; lean_object* v___x_480_; lean_object* v___x_481_; lean_object* v___x_482_; 
v_two_468_ = lean_ctor_get(v_F_461_, 2);
lean_inc_n(v_two_468_, 2);
v_add_469_ = lean_ctor_get(v_F_461_, 4);
lean_inc(v_add_469_);
v_sub_470_ = lean_ctor_get(v_F_461_, 5);
lean_inc(v_sub_470_);
v_mul_471_ = lean_ctor_get(v_F_461_, 6);
lean_inc_n(v_mul_471_, 6);
v_sqrt_472_ = lean_ctor_get(v_F_461_, 9);
lean_inc_n(v_sqrt_472_, 2);
lean_dec_ref(v_F_461_);
v___x_473_ = lean_apply_1(v_sqrt_472_, v_gamma_462_);
v___x_474_ = lean_apply_2(v_mul_471_, v_two_468_, v___x_473_);
lean_inc(v_dt_466_);
v___x_475_ = lean_apply_2(v_mul_471_, v_Lt_464_, v_dt_466_);
v___x_476_ = lean_apply_2(v_mul_471_, v___x_474_, v___x_475_);
v_dY_477_ = lean_apply_2(v_add_469_, v___x_476_, v_dW_467_);
v___x_478_ = lean_apply_1(v_sqrt_472_, v_gamma__f_463_);
v___x_479_ = lean_apply_2(v_mul_471_, v_two_468_, v___x_478_);
v___x_480_ = lean_apply_2(v_mul_471_, v_Lf_465_, v_dt_466_);
v___x_481_ = lean_apply_2(v_mul_471_, v___x_479_, v___x_480_);
v___x_482_ = lean_apply_2(v_sub_470_, v_dY_477_, v___x_481_);
return v___x_482_;
}
}
lean_object* initialize_Init(uint8_t builtin);
lean_object* initialize_Init(uint8_t builtin);
void lean_initialize_runtime_module();
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_levy_x2dcharacterization_LevyCharacterization_BrayAliModel(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
lean_initialize_runtime_module();
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif
