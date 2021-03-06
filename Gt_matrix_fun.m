function out1 = Gt_matrix_fun(CW1_1,CW1_2,CW1_3,CW1_4,CW2_1,CW2_2,CW2_3,CW2_4,d_w,delta1,delta2,delta3,delta4,rW1_1,rW1_2,rW1_3,rW1_4,rW2_1,rW2_2,rW2_3,rW2_4,s_w,theta)
%GT_MATRIX_FUN
%    OUT1 = GT_MATRIX_FUN(CW1_1,CW1_2,CW1_3,CW1_4,CW2_1,CW2_2,CW2_3,CW2_4,D_W,DELTA1,DELTA2,DELTA3,DELTA4,RW1_1,RW1_2,RW1_3,RW1_4,RW2_1,RW2_2,RW2_3,RW2_4,S_W,THETA)

%    This function was generated by the Symbolic Math Toolbox version 8.0.
%    17-Jan-2018 15:15:14

t2 = 1.0./s_w;
t3 = sin(delta1);
t4 = cos(delta1);
t5 = d_w.*t2.*t3.*(1.0./2.0);
t6 = sin(delta2);
t7 = cos(delta2);
t8 = d_w.*t2.*t6.*(1.0./2.0);
t9 = sin(delta3);
t10 = cos(delta3);
t11 = d_w.*t2.*t9.*(1.0./2.0);
t12 = sin(delta4);
t13 = cos(delta4);
t14 = d_w.*t2.*t12.*(1.0./2.0);
t15 = sin(theta);
t16 = cos(theta);
t17 = 1.0./rW1_1;
t18 = 1.0./rW2_1;
t19 = 1.0./rW1_2;
t20 = 1.0./rW2_2;
t21 = 1.0./rW1_3;
t22 = 1.0./rW2_3;
t23 = 1.0./rW1_4;
t24 = 1.0./rW2_4;
t25 = CW1_1.*t4;
t26 = CW2_1.*t3;
t27 = t25+t26;
t28 = CW2_1.*t4;
t29 = d_w.*t2.*t27.*(1.0./2.0);
t30 = CW1_2.*t7;
t31 = CW2_2.*t6;
t32 = t30+t31;
t33 = CW2_2.*t7;
t34 = d_w.*t2.*t32.*(1.0./2.0);
t35 = CW1_3.*t10;
t36 = CW2_3.*t9;
t37 = t35+t36;
t38 = CW2_3.*t10;
t39 = d_w.*t2.*t37.*(1.0./2.0);
t40 = CW1_4.*t13;
t41 = CW2_4.*t12;
t42 = t40+t41;
t43 = CW2_4.*t13;
t44 = d_w.*t2.*t42.*(1.0./2.0);
out1 = reshape([t16,-t15,0.0,t15,t16,0.0,0.0,0.0,1.0,-t2.*t3,t2.*t4,t2.*t27-1.0,-t2.*t6,t2.*t7,t2.*t32-1.0,-t2.*t9,t2.*t10,t2.*t37-1.0,-t2.*t12,t2.*t13,t2.*t42-1.0,t17.*(t4+t5),t17.*(t3-d_w.*t2.*t4.*(1.0./2.0)),-t17.*(t28+t29-CW1_1.*t3),t18.*(t4-t5),t18.*(t3+d_w.*t2.*t4.*(1.0./2.0)),t18.*(-t28+t29+CW1_1.*t3),t19.*(t7+t8),t19.*(t6-d_w.*t2.*t7.*(1.0./2.0)),-t19.*(t33+t34-CW1_2.*t6),t20.*(t7-t8),t20.*(t6+d_w.*t2.*t7.*(1.0./2.0)),t20.*(-t33+t34+CW1_2.*t6),t21.*(t10+t11),t21.*(t9-d_w.*t2.*t10.*(1.0./2.0)),-t21.*(t38+t39-CW1_3.*t9),t22.*(t10-t11),t22.*(t9+d_w.*t2.*t10.*(1.0./2.0)),t22.*(-t38+t39+CW1_3.*t9),t23.*(t13+t14),t23.*(t12-d_w.*t2.*t13.*(1.0./2.0)),-t23.*(t43+t44-CW1_4.*t12),t24.*(t13-t14),t24.*(t12+d_w.*t2.*t13.*(1.0./2.0)),t24.*(-t43+t44+CW1_4.*t12)],[3,15]);
