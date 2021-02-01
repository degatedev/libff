/** @file
 *****************************************************************************

 Implementation of interfaces for initializing MNT4.

 See mnt4_init.hpp .

 *****************************************************************************
 * @author     This file is part of libff, developed by SCIPR Lab
 *             and contributors (see AUTHORS).
 * @copyright  MIT license (see LICENSE file)
 *****************************************************************************/

#include <libff/algebra/curves/mnt/mnt4/mnt4_fields.hpp>

namespace libff {

void init_mnt4_fields()
{
    typedef bigint<mnt4_r_limbs> bigint_r;
    typedef bigint<mnt4_q_limbs> bigint_q;

    assert(sizeof(mp_limb_t) == 8 || sizeof(mp_limb_t) == 4); // Montgomery assumes this

    /* parameters for scalar field Fr */

    mnt4_modulus_r = bigint_r("475922286169261325753349249653048451545124878552823515553267735739164647307408490559963137");
    assert(mnt4_Fr::modulus_is_valid());
    if (sizeof(mp_limb_t) == 8)
    {
        mnt4_Fr::Rsquared = bigint_r("163983144722506446826715124368972380525894397127205577781234305496325861831001705438796139");
        mnt4_Fr::Rcubed = bigint_r("207236281459091063710247635236340312578688659363066707916716212805695955118593239854980171");
        mnt4_Fr::inv = 0xbb4334a3ffffffff;
    }
    if (sizeof(mp_limb_t) == 4)
    {
        mnt4_Fr::Rsquared = bigint_r("163983144722506446826715124368972380525894397127205577781234305496325861831001705438796139");
        mnt4_Fr::Rcubed = bigint_r("207236281459091063710247635236340312578688659363066707916716212805695955118593239854980171");
        mnt4_Fr::inv = 0xffffffff;
    }
    mnt4_Fr::num_bits = 298;
    mnt4_Fr::euler = bigint_r("237961143084630662876674624826524225772562439276411757776633867869582323653704245279981568");
    mnt4_Fr::s = 34;
    mnt4_Fr::t = bigint_r("27702323054502562488973446286577291993024111641153199339359284829066871159442729");
    mnt4_Fr::t_minus_1_over_2 = bigint_r("13851161527251281244486723143288645996512055820576599669679642414533435579721364");
    mnt4_Fr::multiplicative_generator = mnt4_Fr("10");
    mnt4_Fr::root_of_unity = mnt4_Fr("120638817826913173458768829485690099845377008030891618010109772937363554409782252579816313");
    mnt4_Fr::nqr = mnt4_Fr("5");
    mnt4_Fr::nqr_to_t = mnt4_Fr("406220604243090401056429458730298145937262552508985450684842547562990900634752279902740880");

    /* parameters for base field Fq */

    mnt4_modulus_q = bigint_q("475922286169261325753349249653048451545124879242694725395555128576210262817955800483758081");
    assert(mnt4_Fq::modulus_is_valid());
    if (sizeof(mp_limb_t) == 8)
    {
        mnt4_Fq::Rsquared = bigint_q("273000478523237720910981655601160860640083126627235719712980612296263966512828033847775776");
        mnt4_Fq::Rcubed = bigint_q("427298980065529822574935274648041073124704261331681436071990730954930769758106792920349077");
        mnt4_Fq::inv = 0xb071a1b67165ffff;
    }
    if (sizeof(mp_limb_t) == 4)
    {
        mnt4_Fq::Rsquared = bigint_q("273000478523237720910981655601160860640083126627235719712980612296263966512828033847775776");
        mnt4_Fq::Rcubed = bigint_q("427298980065529822574935274648041073124704261331681436071990730954930769758106792920349077");
        mnt4_Fq::inv = 0x7165ffff;
    }
    mnt4_Fq::num_bits = 298;
    mnt4_Fq::euler = bigint_q("237961143084630662876674624826524225772562439621347362697777564288105131408977900241879040");
    mnt4_Fq::s = 17;
    mnt4_Fq::t = bigint_q("3630998887399759870554727551674258816109656366292531779446068791017229177993437198515");
    mnt4_Fq::t_minus_1_over_2 = bigint_q("1815499443699879935277363775837129408054828183146265889723034395508614588996718599257");
    mnt4_Fq::multiplicative_generator = mnt4_Fq("17");
    mnt4_Fq::root_of_unity = mnt4_Fq("264706250571800080758069302369654305530125675521263976034054878017580902343339784464690243");
    mnt4_Fq::nqr = mnt4_Fq("17");
    mnt4_Fq::nqr_to_t = mnt4_Fq("264706250571800080758069302369654305530125675521263976034054878017580902343339784464690243");

    /* parameters for twist field Fq2 */

    mnt4_Fq2::euler = bigint<2*mnt4_q_limbs>("113251011236288135098249345249154230895914381858788918106847214243419142422924133497460817468249854833067260038985710370091920860837014281886963086681184370139950267830740466401280");
    mnt4_Fq2::s = 18;
    mnt4_Fq2::t = bigint<2*mnt4_q_limbs>("864036645784668999467844736092790457885088972921668381552484239528039111503022258739172496553419912972009735404859240494475714575477709059806542104196047745818712370534824115");
    mnt4_Fq2::t_minus_1_over_2 = bigint<2*mnt4_q_limbs>("432018322892334499733922368046395228942544486460834190776242119764019555751511129369586248276709956486004867702429620247237857287738854529903271052098023872909356185267412057");
    mnt4_Fq2::non_residue = mnt4_Fq("17");
    mnt4_Fq2::nqr = mnt4_Fq2(mnt4_Fq("8"),mnt4_Fq("1"));
    mnt4_Fq2::nqr_to_t = mnt4_Fq2(mnt4_Fq("0"),mnt4_Fq("29402818985595053196743631544512156561638230562612542604956687802791427330205135130967658"));
    mnt4_Fq2::Frobenius_coeffs_c1[0] = mnt4_Fq("1");
    mnt4_Fq2::Frobenius_coeffs_c1[1] = mnt4_Fq("475922286169261325753349249653048451545124879242694725395555128576210262817955800483758080");

    /* parameters for Fq4 */

    mnt4_Fq4::euler = bigint<4*mnt4_q_limbs>("256515830920837228603894562946361224104398799265865805633159457364347160648491325197665112074594203843606979074063463732151330068748561097967387024709381297334575804200924440372388"
                                             "70266485480310448412800447687355912222889117273270333186953365310343339095195101362180341777704896596606135620801390396337387451719858347266414533678045654385500808110588904079360");
    mnt4_Fq4::s = 19;
    mnt4_Fq4::t = bigint<4*mnt4_q_limbs>("978530238803242601790979625497288605134577939094031546147001103837383883089032460013065765665413680433681408210996489456754036211961979286069439028584981145227721421054551850785784"
                                         "54080526276819032336427489041732453242832631199914295909703694573758465176372914742204062567538820635246794207768975816106366927031930340829523215019400231878283722345691315");
    mnt4_Fq4::t_minus_1_over_2 = bigint<4*mnt4_q_limbs>("489265119401621300895489812748644302567288969547015773073500551918691941544516230006532882832706840216840704105498244728377018105980989643034719514292490572613860710527275925392892"
                                                        "27040263138409516168213744520866226621416315599957147954851847286879232588186457371102031283769410317623397103884487908053183463515965170414761607509700115939141861172845657");
    mnt4_Fq4::non_residue = mnt4_Fq("17");
    mnt4_Fq4::nqr = mnt4_Fq4(mnt4_Fq2(mnt4_Fq("4"),mnt4_Fq("0")),mnt4_Fq2::one());
    mnt4_Fq4::nqr_to_t = mnt4_Fq4(mnt4_Fq2::zero(),mnt4_Fq2(mnt4_Fq("29121826399401736230321201250169476571908331476055427845679523445723222361523083487327506"),mnt4_Fq("0")));
    mnt4_Fq4::Frobenius_coeffs_c1[0] = mnt4_Fq("1");
    mnt4_Fq4::Frobenius_coeffs_c1[1] = mnt4_Fq("7684163245453501615621351552473337069301082060976805004625011694147890954040864167002308");
    mnt4_Fq4::Frobenius_coeffs_c1[2] = mnt4_Fq("475922286169261325753349249653048451545124879242694725395555128576210262817955800483758080");
    mnt4_Fq4::Frobenius_coeffs_c1[3] = mnt4_Fq("468238122923807824137727898100575114475823797181717920390930116882062371863914936316755773");
}

} // namespace libff
