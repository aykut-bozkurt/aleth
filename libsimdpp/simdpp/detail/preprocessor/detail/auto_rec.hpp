# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# include <simdpp/detail/preprocessor/config/config.hpp>
#
# ifndef SIMDPP_PREPROCESSOR_DETAIL_AUTO_REC_HPP
# define SIMDPP_PREPROCESSOR_DETAIL_AUTO_REC_HPP
#
# include <simdpp/detail/preprocessor/control/iif.hpp>
#
# /* SIMDPP_PP_AUTO_REC */
#
# define SIMDPP_PP_AUTO_REC(pred, n) SIMDPP_PP_NODE_ENTRY_ ## n(pred)
#
# define SIMDPP_PP_NODE_ENTRY_256(p) SIMDPP_PP_NODE_128(p)(p)(p)(p)(p)(p)(p)(p)
# define SIMDPP_PP_NODE_ENTRY_128(p) SIMDPP_PP_NODE_64(p)(p)(p)(p)(p)(p)(p)
# define SIMDPP_PP_NODE_ENTRY_64(p) SIMDPP_PP_NODE_32(p)(p)(p)(p)(p)(p)
# define SIMDPP_PP_NODE_ENTRY_32(p) SIMDPP_PP_NODE_16(p)(p)(p)(p)(p)
# define SIMDPP_PP_NODE_ENTRY_16(p) SIMDPP_PP_NODE_8(p)(p)(p)(p)
# define SIMDPP_PP_NODE_ENTRY_8(p) SIMDPP_PP_NODE_4(p)(p)(p)
# define SIMDPP_PP_NODE_ENTRY_4(p) SIMDPP_PP_NODE_2(p)(p)
# define SIMDPP_PP_NODE_ENTRY_2(p) SIMDPP_PP_NODE_1(p)
#
# define SIMDPP_PP_NODE_128(p) SIMDPP_PP_IIF(p(128), SIMDPP_PP_NODE_64, SIMDPP_PP_NODE_192)
#    define SIMDPP_PP_NODE_64(p) SIMDPP_PP_IIF(p(64), SIMDPP_PP_NODE_32, SIMDPP_PP_NODE_96)
#        define SIMDPP_PP_NODE_32(p) SIMDPP_PP_IIF(p(32), SIMDPP_PP_NODE_16, SIMDPP_PP_NODE_48)
#            define SIMDPP_PP_NODE_16(p) SIMDPP_PP_IIF(p(16), SIMDPP_PP_NODE_8, SIMDPP_PP_NODE_24)
#                define SIMDPP_PP_NODE_8(p) SIMDPP_PP_IIF(p(8), SIMDPP_PP_NODE_4, SIMDPP_PP_NODE_12)
#                    define SIMDPP_PP_NODE_4(p) SIMDPP_PP_IIF(p(4), SIMDPP_PP_NODE_2, SIMDPP_PP_NODE_6)
#                        define SIMDPP_PP_NODE_2(p) SIMDPP_PP_IIF(p(2), SIMDPP_PP_NODE_1, SIMDPP_PP_NODE_3)
#                            define SIMDPP_PP_NODE_1(p) SIMDPP_PP_IIF(p(1), 1, 2)
#                            define SIMDPP_PP_NODE_3(p) SIMDPP_PP_IIF(p(3), 3, 4)
#                        define SIMDPP_PP_NODE_6(p) SIMDPP_PP_IIF(p(6), SIMDPP_PP_NODE_5, SIMDPP_PP_NODE_7)
#                            define SIMDPP_PP_NODE_5(p) SIMDPP_PP_IIF(p(5), 5, 6)
#                            define SIMDPP_PP_NODE_7(p) SIMDPP_PP_IIF(p(7), 7, 8)
#                    define SIMDPP_PP_NODE_12(p) SIMDPP_PP_IIF(p(12), SIMDPP_PP_NODE_10, SIMDPP_PP_NODE_14)
#                        define SIMDPP_PP_NODE_10(p) SIMDPP_PP_IIF(p(10), SIMDPP_PP_NODE_9, SIMDPP_PP_NODE_11)
#                            define SIMDPP_PP_NODE_9(p) SIMDPP_PP_IIF(p(9), 9, 10)
#                            define SIMDPP_PP_NODE_11(p) SIMDPP_PP_IIF(p(11), 11, 12)
#                        define SIMDPP_PP_NODE_14(p) SIMDPP_PP_IIF(p(14), SIMDPP_PP_NODE_13, SIMDPP_PP_NODE_15)
#                            define SIMDPP_PP_NODE_13(p) SIMDPP_PP_IIF(p(13), 13, 14)
#                            define SIMDPP_PP_NODE_15(p) SIMDPP_PP_IIF(p(15), 15, 16)
#                define SIMDPP_PP_NODE_24(p) SIMDPP_PP_IIF(p(24), SIMDPP_PP_NODE_20, SIMDPP_PP_NODE_28)
#                    define SIMDPP_PP_NODE_20(p) SIMDPP_PP_IIF(p(20), SIMDPP_PP_NODE_18, SIMDPP_PP_NODE_22)
#                        define SIMDPP_PP_NODE_18(p) SIMDPP_PP_IIF(p(18), SIMDPP_PP_NODE_17, SIMDPP_PP_NODE_19)
#                            define SIMDPP_PP_NODE_17(p) SIMDPP_PP_IIF(p(17), 17, 18)
#                            define SIMDPP_PP_NODE_19(p) SIMDPP_PP_IIF(p(19), 19, 20)
#                        define SIMDPP_PP_NODE_22(p) SIMDPP_PP_IIF(p(22), SIMDPP_PP_NODE_21, SIMDPP_PP_NODE_23)
#                            define SIMDPP_PP_NODE_21(p) SIMDPP_PP_IIF(p(21), 21, 22)
#                            define SIMDPP_PP_NODE_23(p) SIMDPP_PP_IIF(p(23), 23, 24)
#                    define SIMDPP_PP_NODE_28(p) SIMDPP_PP_IIF(p(28), SIMDPP_PP_NODE_26, SIMDPP_PP_NODE_30)
#                        define SIMDPP_PP_NODE_26(p) SIMDPP_PP_IIF(p(26), SIMDPP_PP_NODE_25, SIMDPP_PP_NODE_27)
#                            define SIMDPP_PP_NODE_25(p) SIMDPP_PP_IIF(p(25), 25, 26)
#                            define SIMDPP_PP_NODE_27(p) SIMDPP_PP_IIF(p(27), 27, 28)
#                        define SIMDPP_PP_NODE_30(p) SIMDPP_PP_IIF(p(30), SIMDPP_PP_NODE_29, SIMDPP_PP_NODE_31)
#                            define SIMDPP_PP_NODE_29(p) SIMDPP_PP_IIF(p(29), 29, 30)
#                            define SIMDPP_PP_NODE_31(p) SIMDPP_PP_IIF(p(31), 31, 32)
#            define SIMDPP_PP_NODE_48(p) SIMDPP_PP_IIF(p(48), SIMDPP_PP_NODE_40, SIMDPP_PP_NODE_56)
#                define SIMDPP_PP_NODE_40(p) SIMDPP_PP_IIF(p(40), SIMDPP_PP_NODE_36, SIMDPP_PP_NODE_44)
#                    define SIMDPP_PP_NODE_36(p) SIMDPP_PP_IIF(p(36), SIMDPP_PP_NODE_34, SIMDPP_PP_NODE_38)
#                        define SIMDPP_PP_NODE_34(p) SIMDPP_PP_IIF(p(34), SIMDPP_PP_NODE_33, SIMDPP_PP_NODE_35)
#                            define SIMDPP_PP_NODE_33(p) SIMDPP_PP_IIF(p(33), 33, 34)
#                            define SIMDPP_PP_NODE_35(p) SIMDPP_PP_IIF(p(35), 35, 36)
#                        define SIMDPP_PP_NODE_38(p) SIMDPP_PP_IIF(p(38), SIMDPP_PP_NODE_37, SIMDPP_PP_NODE_39)
#                            define SIMDPP_PP_NODE_37(p) SIMDPP_PP_IIF(p(37), 37, 38)
#                            define SIMDPP_PP_NODE_39(p) SIMDPP_PP_IIF(p(39), 39, 40)
#                    define SIMDPP_PP_NODE_44(p) SIMDPP_PP_IIF(p(44), SIMDPP_PP_NODE_42, SIMDPP_PP_NODE_46)
#                        define SIMDPP_PP_NODE_42(p) SIMDPP_PP_IIF(p(42), SIMDPP_PP_NODE_41, SIMDPP_PP_NODE_43)
#                            define SIMDPP_PP_NODE_41(p) SIMDPP_PP_IIF(p(41), 41, 42)
#                            define SIMDPP_PP_NODE_43(p) SIMDPP_PP_IIF(p(43), 43, 44)
#                        define SIMDPP_PP_NODE_46(p) SIMDPP_PP_IIF(p(46), SIMDPP_PP_NODE_45, SIMDPP_PP_NODE_47)
#                            define SIMDPP_PP_NODE_45(p) SIMDPP_PP_IIF(p(45), 45, 46)
#                            define SIMDPP_PP_NODE_47(p) SIMDPP_PP_IIF(p(47), 47, 48)
#                define SIMDPP_PP_NODE_56(p) SIMDPP_PP_IIF(p(56), SIMDPP_PP_NODE_52, SIMDPP_PP_NODE_60)
#                    define SIMDPP_PP_NODE_52(p) SIMDPP_PP_IIF(p(52), SIMDPP_PP_NODE_50, SIMDPP_PP_NODE_54)
#                        define SIMDPP_PP_NODE_50(p) SIMDPP_PP_IIF(p(50), SIMDPP_PP_NODE_49, SIMDPP_PP_NODE_51)
#                            define SIMDPP_PP_NODE_49(p) SIMDPP_PP_IIF(p(49), 49, 50)
#                            define SIMDPP_PP_NODE_51(p) SIMDPP_PP_IIF(p(51), 51, 52)
#                        define SIMDPP_PP_NODE_54(p) SIMDPP_PP_IIF(p(54), SIMDPP_PP_NODE_53, SIMDPP_PP_NODE_55)
#                            define SIMDPP_PP_NODE_53(p) SIMDPP_PP_IIF(p(53), 53, 54)
#                            define SIMDPP_PP_NODE_55(p) SIMDPP_PP_IIF(p(55), 55, 56)
#                    define SIMDPP_PP_NODE_60(p) SIMDPP_PP_IIF(p(60), SIMDPP_PP_NODE_58, SIMDPP_PP_NODE_62)
#                        define SIMDPP_PP_NODE_58(p) SIMDPP_PP_IIF(p(58), SIMDPP_PP_NODE_57, SIMDPP_PP_NODE_59)
#                            define SIMDPP_PP_NODE_57(p) SIMDPP_PP_IIF(p(57), 57, 58)
#                            define SIMDPP_PP_NODE_59(p) SIMDPP_PP_IIF(p(59), 59, 60)
#                        define SIMDPP_PP_NODE_62(p) SIMDPP_PP_IIF(p(62), SIMDPP_PP_NODE_61, SIMDPP_PP_NODE_63)
#                            define SIMDPP_PP_NODE_61(p) SIMDPP_PP_IIF(p(61), 61, 62)
#                            define SIMDPP_PP_NODE_63(p) SIMDPP_PP_IIF(p(63), 63, 64)
#        define SIMDPP_PP_NODE_96(p) SIMDPP_PP_IIF(p(96), SIMDPP_PP_NODE_80, SIMDPP_PP_NODE_112)
#            define SIMDPP_PP_NODE_80(p) SIMDPP_PP_IIF(p(80), SIMDPP_PP_NODE_72, SIMDPP_PP_NODE_88)
#                define SIMDPP_PP_NODE_72(p) SIMDPP_PP_IIF(p(72), SIMDPP_PP_NODE_68, SIMDPP_PP_NODE_76)
#                    define SIMDPP_PP_NODE_68(p) SIMDPP_PP_IIF(p(68), SIMDPP_PP_NODE_66, SIMDPP_PP_NODE_70)
#                        define SIMDPP_PP_NODE_66(p) SIMDPP_PP_IIF(p(66), SIMDPP_PP_NODE_65, SIMDPP_PP_NODE_67)
#                            define SIMDPP_PP_NODE_65(p) SIMDPP_PP_IIF(p(65), 65, 66)
#                            define SIMDPP_PP_NODE_67(p) SIMDPP_PP_IIF(p(67), 67, 68)
#                        define SIMDPP_PP_NODE_70(p) SIMDPP_PP_IIF(p(70), SIMDPP_PP_NODE_69, SIMDPP_PP_NODE_71)
#                            define SIMDPP_PP_NODE_69(p) SIMDPP_PP_IIF(p(69), 69, 70)
#                            define SIMDPP_PP_NODE_71(p) SIMDPP_PP_IIF(p(71), 71, 72)
#                    define SIMDPP_PP_NODE_76(p) SIMDPP_PP_IIF(p(76), SIMDPP_PP_NODE_74, SIMDPP_PP_NODE_78)
#                        define SIMDPP_PP_NODE_74(p) SIMDPP_PP_IIF(p(74), SIMDPP_PP_NODE_73, SIMDPP_PP_NODE_75)
#                            define SIMDPP_PP_NODE_73(p) SIMDPP_PP_IIF(p(73), 73, 74)
#                            define SIMDPP_PP_NODE_75(p) SIMDPP_PP_IIF(p(75), 75, 76)
#                        define SIMDPP_PP_NODE_78(p) SIMDPP_PP_IIF(p(78), SIMDPP_PP_NODE_77, SIMDPP_PP_NODE_79)
#                            define SIMDPP_PP_NODE_77(p) SIMDPP_PP_IIF(p(77), 77, 78)
#                            define SIMDPP_PP_NODE_79(p) SIMDPP_PP_IIF(p(79), 79, 80)
#                define SIMDPP_PP_NODE_88(p) SIMDPP_PP_IIF(p(88), SIMDPP_PP_NODE_84, SIMDPP_PP_NODE_92)
#                    define SIMDPP_PP_NODE_84(p) SIMDPP_PP_IIF(p(84), SIMDPP_PP_NODE_82, SIMDPP_PP_NODE_86)
#                        define SIMDPP_PP_NODE_82(p) SIMDPP_PP_IIF(p(82), SIMDPP_PP_NODE_81, SIMDPP_PP_NODE_83)
#                            define SIMDPP_PP_NODE_81(p) SIMDPP_PP_IIF(p(81), 81, 82)
#                            define SIMDPP_PP_NODE_83(p) SIMDPP_PP_IIF(p(83), 83, 84)
#                        define SIMDPP_PP_NODE_86(p) SIMDPP_PP_IIF(p(86), SIMDPP_PP_NODE_85, SIMDPP_PP_NODE_87)
#                            define SIMDPP_PP_NODE_85(p) SIMDPP_PP_IIF(p(85), 85, 86)
#                            define SIMDPP_PP_NODE_87(p) SIMDPP_PP_IIF(p(87), 87, 88)
#                    define SIMDPP_PP_NODE_92(p) SIMDPP_PP_IIF(p(92), SIMDPP_PP_NODE_90, SIMDPP_PP_NODE_94)
#                        define SIMDPP_PP_NODE_90(p) SIMDPP_PP_IIF(p(90), SIMDPP_PP_NODE_89, SIMDPP_PP_NODE_91)
#                            define SIMDPP_PP_NODE_89(p) SIMDPP_PP_IIF(p(89), 89, 90)
#                            define SIMDPP_PP_NODE_91(p) SIMDPP_PP_IIF(p(91), 91, 92)
#                        define SIMDPP_PP_NODE_94(p) SIMDPP_PP_IIF(p(94), SIMDPP_PP_NODE_93, SIMDPP_PP_NODE_95)
#                            define SIMDPP_PP_NODE_93(p) SIMDPP_PP_IIF(p(93), 93, 94)
#                            define SIMDPP_PP_NODE_95(p) SIMDPP_PP_IIF(p(95), 95, 96)
#            define SIMDPP_PP_NODE_112(p) SIMDPP_PP_IIF(p(112), SIMDPP_PP_NODE_104, SIMDPP_PP_NODE_120)
#                define SIMDPP_PP_NODE_104(p) SIMDPP_PP_IIF(p(104), SIMDPP_PP_NODE_100, SIMDPP_PP_NODE_108)
#                    define SIMDPP_PP_NODE_100(p) SIMDPP_PP_IIF(p(100), SIMDPP_PP_NODE_98, SIMDPP_PP_NODE_102)
#                        define SIMDPP_PP_NODE_98(p) SIMDPP_PP_IIF(p(98), SIMDPP_PP_NODE_97, SIMDPP_PP_NODE_99)
#                            define SIMDPP_PP_NODE_97(p) SIMDPP_PP_IIF(p(97), 97, 98)
#                            define SIMDPP_PP_NODE_99(p) SIMDPP_PP_IIF(p(99), 99, 100)
#                        define SIMDPP_PP_NODE_102(p) SIMDPP_PP_IIF(p(102), SIMDPP_PP_NODE_101, SIMDPP_PP_NODE_103)
#                            define SIMDPP_PP_NODE_101(p) SIMDPP_PP_IIF(p(101), 101, 102)
#                            define SIMDPP_PP_NODE_103(p) SIMDPP_PP_IIF(p(103), 103, 104)
#                    define SIMDPP_PP_NODE_108(p) SIMDPP_PP_IIF(p(108), SIMDPP_PP_NODE_106, SIMDPP_PP_NODE_110)
#                        define SIMDPP_PP_NODE_106(p) SIMDPP_PP_IIF(p(106), SIMDPP_PP_NODE_105, SIMDPP_PP_NODE_107)
#                            define SIMDPP_PP_NODE_105(p) SIMDPP_PP_IIF(p(105), 105, 106)
#                            define SIMDPP_PP_NODE_107(p) SIMDPP_PP_IIF(p(107), 107, 108)
#                        define SIMDPP_PP_NODE_110(p) SIMDPP_PP_IIF(p(110), SIMDPP_PP_NODE_109, SIMDPP_PP_NODE_111)
#                            define SIMDPP_PP_NODE_109(p) SIMDPP_PP_IIF(p(109), 109, 110)
#                            define SIMDPP_PP_NODE_111(p) SIMDPP_PP_IIF(p(111), 111, 112)
#                define SIMDPP_PP_NODE_120(p) SIMDPP_PP_IIF(p(120), SIMDPP_PP_NODE_116, SIMDPP_PP_NODE_124)
#                    define SIMDPP_PP_NODE_116(p) SIMDPP_PP_IIF(p(116), SIMDPP_PP_NODE_114, SIMDPP_PP_NODE_118)
#                        define SIMDPP_PP_NODE_114(p) SIMDPP_PP_IIF(p(114), SIMDPP_PP_NODE_113, SIMDPP_PP_NODE_115)
#                            define SIMDPP_PP_NODE_113(p) SIMDPP_PP_IIF(p(113), 113, 114)
#                            define SIMDPP_PP_NODE_115(p) SIMDPP_PP_IIF(p(115), 115, 116)
#                        define SIMDPP_PP_NODE_118(p) SIMDPP_PP_IIF(p(118), SIMDPP_PP_NODE_117, SIMDPP_PP_NODE_119)
#                            define SIMDPP_PP_NODE_117(p) SIMDPP_PP_IIF(p(117), 117, 118)
#                            define SIMDPP_PP_NODE_119(p) SIMDPP_PP_IIF(p(119), 119, 120)
#                    define SIMDPP_PP_NODE_124(p) SIMDPP_PP_IIF(p(124), SIMDPP_PP_NODE_122, SIMDPP_PP_NODE_126)
#                        define SIMDPP_PP_NODE_122(p) SIMDPP_PP_IIF(p(122), SIMDPP_PP_NODE_121, SIMDPP_PP_NODE_123)
#                            define SIMDPP_PP_NODE_121(p) SIMDPP_PP_IIF(p(121), 121, 122)
#                            define SIMDPP_PP_NODE_123(p) SIMDPP_PP_IIF(p(123), 123, 124)
#                        define SIMDPP_PP_NODE_126(p) SIMDPP_PP_IIF(p(126), SIMDPP_PP_NODE_125, SIMDPP_PP_NODE_127)
#                            define SIMDPP_PP_NODE_125(p) SIMDPP_PP_IIF(p(125), 125, 126)
#                            define SIMDPP_PP_NODE_127(p) SIMDPP_PP_IIF(p(127), 127, 128)
#    define SIMDPP_PP_NODE_192(p) SIMDPP_PP_IIF(p(192), SIMDPP_PP_NODE_160, SIMDPP_PP_NODE_224)
#        define SIMDPP_PP_NODE_160(p) SIMDPP_PP_IIF(p(160), SIMDPP_PP_NODE_144, SIMDPP_PP_NODE_176)
#            define SIMDPP_PP_NODE_144(p) SIMDPP_PP_IIF(p(144), SIMDPP_PP_NODE_136, SIMDPP_PP_NODE_152)
#                define SIMDPP_PP_NODE_136(p) SIMDPP_PP_IIF(p(136), SIMDPP_PP_NODE_132, SIMDPP_PP_NODE_140)
#                    define SIMDPP_PP_NODE_132(p) SIMDPP_PP_IIF(p(132), SIMDPP_PP_NODE_130, SIMDPP_PP_NODE_134)
#                        define SIMDPP_PP_NODE_130(p) SIMDPP_PP_IIF(p(130), SIMDPP_PP_NODE_129, SIMDPP_PP_NODE_131)
#                            define SIMDPP_PP_NODE_129(p) SIMDPP_PP_IIF(p(129), 129, 130)
#                            define SIMDPP_PP_NODE_131(p) SIMDPP_PP_IIF(p(131), 131, 132)
#                        define SIMDPP_PP_NODE_134(p) SIMDPP_PP_IIF(p(134), SIMDPP_PP_NODE_133, SIMDPP_PP_NODE_135)
#                            define SIMDPP_PP_NODE_133(p) SIMDPP_PP_IIF(p(133), 133, 134)
#                            define SIMDPP_PP_NODE_135(p) SIMDPP_PP_IIF(p(135), 135, 136)
#                    define SIMDPP_PP_NODE_140(p) SIMDPP_PP_IIF(p(140), SIMDPP_PP_NODE_138, SIMDPP_PP_NODE_142)
#                        define SIMDPP_PP_NODE_138(p) SIMDPP_PP_IIF(p(138), SIMDPP_PP_NODE_137, SIMDPP_PP_NODE_139)
#                            define SIMDPP_PP_NODE_137(p) SIMDPP_PP_IIF(p(137), 137, 138)
#                            define SIMDPP_PP_NODE_139(p) SIMDPP_PP_IIF(p(139), 139, 140)
#                        define SIMDPP_PP_NODE_142(p) SIMDPP_PP_IIF(p(142), SIMDPP_PP_NODE_141, SIMDPP_PP_NODE_143)
#                            define SIMDPP_PP_NODE_141(p) SIMDPP_PP_IIF(p(141), 141, 142)
#                            define SIMDPP_PP_NODE_143(p) SIMDPP_PP_IIF(p(143), 143, 144)
#                define SIMDPP_PP_NODE_152(p) SIMDPP_PP_IIF(p(152), SIMDPP_PP_NODE_148, SIMDPP_PP_NODE_156)
#                    define SIMDPP_PP_NODE_148(p) SIMDPP_PP_IIF(p(148), SIMDPP_PP_NODE_146, SIMDPP_PP_NODE_150)
#                        define SIMDPP_PP_NODE_146(p) SIMDPP_PP_IIF(p(146), SIMDPP_PP_NODE_145, SIMDPP_PP_NODE_147)
#                            define SIMDPP_PP_NODE_145(p) SIMDPP_PP_IIF(p(145), 145, 146)
#                            define SIMDPP_PP_NODE_147(p) SIMDPP_PP_IIF(p(147), 147, 148)
#                        define SIMDPP_PP_NODE_150(p) SIMDPP_PP_IIF(p(150), SIMDPP_PP_NODE_149, SIMDPP_PP_NODE_151)
#                            define SIMDPP_PP_NODE_149(p) SIMDPP_PP_IIF(p(149), 149, 150)
#                            define SIMDPP_PP_NODE_151(p) SIMDPP_PP_IIF(p(151), 151, 152)
#                    define SIMDPP_PP_NODE_156(p) SIMDPP_PP_IIF(p(156), SIMDPP_PP_NODE_154, SIMDPP_PP_NODE_158)
#                        define SIMDPP_PP_NODE_154(p) SIMDPP_PP_IIF(p(154), SIMDPP_PP_NODE_153, SIMDPP_PP_NODE_155)
#                            define SIMDPP_PP_NODE_153(p) SIMDPP_PP_IIF(p(153), 153, 154)
#                            define SIMDPP_PP_NODE_155(p) SIMDPP_PP_IIF(p(155), 155, 156)
#                        define SIMDPP_PP_NODE_158(p) SIMDPP_PP_IIF(p(158), SIMDPP_PP_NODE_157, SIMDPP_PP_NODE_159)
#                            define SIMDPP_PP_NODE_157(p) SIMDPP_PP_IIF(p(157), 157, 158)
#                            define SIMDPP_PP_NODE_159(p) SIMDPP_PP_IIF(p(159), 159, 160)
#            define SIMDPP_PP_NODE_176(p) SIMDPP_PP_IIF(p(176), SIMDPP_PP_NODE_168, SIMDPP_PP_NODE_184)
#                define SIMDPP_PP_NODE_168(p) SIMDPP_PP_IIF(p(168), SIMDPP_PP_NODE_164, SIMDPP_PP_NODE_172)
#                    define SIMDPP_PP_NODE_164(p) SIMDPP_PP_IIF(p(164), SIMDPP_PP_NODE_162, SIMDPP_PP_NODE_166)
#                        define SIMDPP_PP_NODE_162(p) SIMDPP_PP_IIF(p(162), SIMDPP_PP_NODE_161, SIMDPP_PP_NODE_163)
#                            define SIMDPP_PP_NODE_161(p) SIMDPP_PP_IIF(p(161), 161, 162)
#                            define SIMDPP_PP_NODE_163(p) SIMDPP_PP_IIF(p(163), 163, 164)
#                        define SIMDPP_PP_NODE_166(p) SIMDPP_PP_IIF(p(166), SIMDPP_PP_NODE_165, SIMDPP_PP_NODE_167)
#                            define SIMDPP_PP_NODE_165(p) SIMDPP_PP_IIF(p(165), 165, 166)
#                            define SIMDPP_PP_NODE_167(p) SIMDPP_PP_IIF(p(167), 167, 168)
#                    define SIMDPP_PP_NODE_172(p) SIMDPP_PP_IIF(p(172), SIMDPP_PP_NODE_170, SIMDPP_PP_NODE_174)
#                        define SIMDPP_PP_NODE_170(p) SIMDPP_PP_IIF(p(170), SIMDPP_PP_NODE_169, SIMDPP_PP_NODE_171)
#                            define SIMDPP_PP_NODE_169(p) SIMDPP_PP_IIF(p(169), 169, 170)
#                            define SIMDPP_PP_NODE_171(p) SIMDPP_PP_IIF(p(171), 171, 172)
#                        define SIMDPP_PP_NODE_174(p) SIMDPP_PP_IIF(p(174), SIMDPP_PP_NODE_173, SIMDPP_PP_NODE_175)
#                            define SIMDPP_PP_NODE_173(p) SIMDPP_PP_IIF(p(173), 173, 174)
#                            define SIMDPP_PP_NODE_175(p) SIMDPP_PP_IIF(p(175), 175, 176)
#                define SIMDPP_PP_NODE_184(p) SIMDPP_PP_IIF(p(184), SIMDPP_PP_NODE_180, SIMDPP_PP_NODE_188)
#                    define SIMDPP_PP_NODE_180(p) SIMDPP_PP_IIF(p(180), SIMDPP_PP_NODE_178, SIMDPP_PP_NODE_182)
#                        define SIMDPP_PP_NODE_178(p) SIMDPP_PP_IIF(p(178), SIMDPP_PP_NODE_177, SIMDPP_PP_NODE_179)
#                            define SIMDPP_PP_NODE_177(p) SIMDPP_PP_IIF(p(177), 177, 178)
#                            define SIMDPP_PP_NODE_179(p) SIMDPP_PP_IIF(p(179), 179, 180)
#                        define SIMDPP_PP_NODE_182(p) SIMDPP_PP_IIF(p(182), SIMDPP_PP_NODE_181, SIMDPP_PP_NODE_183)
#                            define SIMDPP_PP_NODE_181(p) SIMDPP_PP_IIF(p(181), 181, 182)
#                            define SIMDPP_PP_NODE_183(p) SIMDPP_PP_IIF(p(183), 183, 184)
#                    define SIMDPP_PP_NODE_188(p) SIMDPP_PP_IIF(p(188), SIMDPP_PP_NODE_186, SIMDPP_PP_NODE_190)
#                        define SIMDPP_PP_NODE_186(p) SIMDPP_PP_IIF(p(186), SIMDPP_PP_NODE_185, SIMDPP_PP_NODE_187)
#                            define SIMDPP_PP_NODE_185(p) SIMDPP_PP_IIF(p(185), 185, 186)
#                            define SIMDPP_PP_NODE_187(p) SIMDPP_PP_IIF(p(187), 187, 188)
#                        define SIMDPP_PP_NODE_190(p) SIMDPP_PP_IIF(p(190), SIMDPP_PP_NODE_189, SIMDPP_PP_NODE_191)
#                            define SIMDPP_PP_NODE_189(p) SIMDPP_PP_IIF(p(189), 189, 190)
#                            define SIMDPP_PP_NODE_191(p) SIMDPP_PP_IIF(p(191), 191, 192)
#        define SIMDPP_PP_NODE_224(p) SIMDPP_PP_IIF(p(224), SIMDPP_PP_NODE_208, SIMDPP_PP_NODE_240)
#            define SIMDPP_PP_NODE_208(p) SIMDPP_PP_IIF(p(208), SIMDPP_PP_NODE_200, SIMDPP_PP_NODE_216)
#                define SIMDPP_PP_NODE_200(p) SIMDPP_PP_IIF(p(200), SIMDPP_PP_NODE_196, SIMDPP_PP_NODE_204)
#                    define SIMDPP_PP_NODE_196(p) SIMDPP_PP_IIF(p(196), SIMDPP_PP_NODE_194, SIMDPP_PP_NODE_198)
#                        define SIMDPP_PP_NODE_194(p) SIMDPP_PP_IIF(p(194), SIMDPP_PP_NODE_193, SIMDPP_PP_NODE_195)
#                            define SIMDPP_PP_NODE_193(p) SIMDPP_PP_IIF(p(193), 193, 194)
#                            define SIMDPP_PP_NODE_195(p) SIMDPP_PP_IIF(p(195), 195, 196)
#                        define SIMDPP_PP_NODE_198(p) SIMDPP_PP_IIF(p(198), SIMDPP_PP_NODE_197, SIMDPP_PP_NODE_199)
#                            define SIMDPP_PP_NODE_197(p) SIMDPP_PP_IIF(p(197), 197, 198)
#                            define SIMDPP_PP_NODE_199(p) SIMDPP_PP_IIF(p(199), 199, 200)
#                    define SIMDPP_PP_NODE_204(p) SIMDPP_PP_IIF(p(204), SIMDPP_PP_NODE_202, SIMDPP_PP_NODE_206)
#                        define SIMDPP_PP_NODE_202(p) SIMDPP_PP_IIF(p(202), SIMDPP_PP_NODE_201, SIMDPP_PP_NODE_203)
#                            define SIMDPP_PP_NODE_201(p) SIMDPP_PP_IIF(p(201), 201, 202)
#                            define SIMDPP_PP_NODE_203(p) SIMDPP_PP_IIF(p(203), 203, 204)
#                        define SIMDPP_PP_NODE_206(p) SIMDPP_PP_IIF(p(206), SIMDPP_PP_NODE_205, SIMDPP_PP_NODE_207)
#                            define SIMDPP_PP_NODE_205(p) SIMDPP_PP_IIF(p(205), 205, 206)
#                            define SIMDPP_PP_NODE_207(p) SIMDPP_PP_IIF(p(207), 207, 208)
#                define SIMDPP_PP_NODE_216(p) SIMDPP_PP_IIF(p(216), SIMDPP_PP_NODE_212, SIMDPP_PP_NODE_220)
#                    define SIMDPP_PP_NODE_212(p) SIMDPP_PP_IIF(p(212), SIMDPP_PP_NODE_210, SIMDPP_PP_NODE_214)
#                        define SIMDPP_PP_NODE_210(p) SIMDPP_PP_IIF(p(210), SIMDPP_PP_NODE_209, SIMDPP_PP_NODE_211)
#                            define SIMDPP_PP_NODE_209(p) SIMDPP_PP_IIF(p(209), 209, 210)
#                            define SIMDPP_PP_NODE_211(p) SIMDPP_PP_IIF(p(211), 211, 212)
#                        define SIMDPP_PP_NODE_214(p) SIMDPP_PP_IIF(p(214), SIMDPP_PP_NODE_213, SIMDPP_PP_NODE_215)
#                            define SIMDPP_PP_NODE_213(p) SIMDPP_PP_IIF(p(213), 213, 214)
#                            define SIMDPP_PP_NODE_215(p) SIMDPP_PP_IIF(p(215), 215, 216)
#                    define SIMDPP_PP_NODE_220(p) SIMDPP_PP_IIF(p(220), SIMDPP_PP_NODE_218, SIMDPP_PP_NODE_222)
#                        define SIMDPP_PP_NODE_218(p) SIMDPP_PP_IIF(p(218), SIMDPP_PP_NODE_217, SIMDPP_PP_NODE_219)
#                            define SIMDPP_PP_NODE_217(p) SIMDPP_PP_IIF(p(217), 217, 218)
#                            define SIMDPP_PP_NODE_219(p) SIMDPP_PP_IIF(p(219), 219, 220)
#                        define SIMDPP_PP_NODE_222(p) SIMDPP_PP_IIF(p(222), SIMDPP_PP_NODE_221, SIMDPP_PP_NODE_223)
#                            define SIMDPP_PP_NODE_221(p) SIMDPP_PP_IIF(p(221), 221, 222)
#                            define SIMDPP_PP_NODE_223(p) SIMDPP_PP_IIF(p(223), 223, 224)
#            define SIMDPP_PP_NODE_240(p) SIMDPP_PP_IIF(p(240), SIMDPP_PP_NODE_232, SIMDPP_PP_NODE_248)
#                define SIMDPP_PP_NODE_232(p) SIMDPP_PP_IIF(p(232), SIMDPP_PP_NODE_228, SIMDPP_PP_NODE_236)
#                    define SIMDPP_PP_NODE_228(p) SIMDPP_PP_IIF(p(228), SIMDPP_PP_NODE_226, SIMDPP_PP_NODE_230)
#                        define SIMDPP_PP_NODE_226(p) SIMDPP_PP_IIF(p(226), SIMDPP_PP_NODE_225, SIMDPP_PP_NODE_227)
#                            define SIMDPP_PP_NODE_225(p) SIMDPP_PP_IIF(p(225), 225, 226)
#                            define SIMDPP_PP_NODE_227(p) SIMDPP_PP_IIF(p(227), 227, 228)
#                        define SIMDPP_PP_NODE_230(p) SIMDPP_PP_IIF(p(230), SIMDPP_PP_NODE_229, SIMDPP_PP_NODE_231)
#                            define SIMDPP_PP_NODE_229(p) SIMDPP_PP_IIF(p(229), 229, 230)
#                            define SIMDPP_PP_NODE_231(p) SIMDPP_PP_IIF(p(231), 231, 232)
#                    define SIMDPP_PP_NODE_236(p) SIMDPP_PP_IIF(p(236), SIMDPP_PP_NODE_234, SIMDPP_PP_NODE_238)
#                        define SIMDPP_PP_NODE_234(p) SIMDPP_PP_IIF(p(234), SIMDPP_PP_NODE_233, SIMDPP_PP_NODE_235)
#                            define SIMDPP_PP_NODE_233(p) SIMDPP_PP_IIF(p(233), 233, 234)
#                            define SIMDPP_PP_NODE_235(p) SIMDPP_PP_IIF(p(235), 235, 236)
#                        define SIMDPP_PP_NODE_238(p) SIMDPP_PP_IIF(p(238), SIMDPP_PP_NODE_237, SIMDPP_PP_NODE_239)
#                            define SIMDPP_PP_NODE_237(p) SIMDPP_PP_IIF(p(237), 237, 238)
#                            define SIMDPP_PP_NODE_239(p) SIMDPP_PP_IIF(p(239), 239, 240)
#                define SIMDPP_PP_NODE_248(p) SIMDPP_PP_IIF(p(248), SIMDPP_PP_NODE_244, SIMDPP_PP_NODE_252)
#                    define SIMDPP_PP_NODE_244(p) SIMDPP_PP_IIF(p(244), SIMDPP_PP_NODE_242, SIMDPP_PP_NODE_246)
#                        define SIMDPP_PP_NODE_242(p) SIMDPP_PP_IIF(p(242), SIMDPP_PP_NODE_241, SIMDPP_PP_NODE_243)
#                            define SIMDPP_PP_NODE_241(p) SIMDPP_PP_IIF(p(241), 241, 242)
#                            define SIMDPP_PP_NODE_243(p) SIMDPP_PP_IIF(p(243), 243, 244)
#                        define SIMDPP_PP_NODE_246(p) SIMDPP_PP_IIF(p(246), SIMDPP_PP_NODE_245, SIMDPP_PP_NODE_247)
#                            define SIMDPP_PP_NODE_245(p) SIMDPP_PP_IIF(p(245), 245, 246)
#                            define SIMDPP_PP_NODE_247(p) SIMDPP_PP_IIF(p(247), 247, 248)
#                    define SIMDPP_PP_NODE_252(p) SIMDPP_PP_IIF(p(252), SIMDPP_PP_NODE_250, SIMDPP_PP_NODE_254)
#                        define SIMDPP_PP_NODE_250(p) SIMDPP_PP_IIF(p(250), SIMDPP_PP_NODE_249, SIMDPP_PP_NODE_251)
#                            define SIMDPP_PP_NODE_249(p) SIMDPP_PP_IIF(p(249), 249, 250)
#                            define SIMDPP_PP_NODE_251(p) SIMDPP_PP_IIF(p(251), 251, 252)
#                        define SIMDPP_PP_NODE_254(p) SIMDPP_PP_IIF(p(254), SIMDPP_PP_NODE_253, SIMDPP_PP_NODE_255)
#                            define SIMDPP_PP_NODE_253(p) SIMDPP_PP_IIF(p(253), 253, 254)
#                            define SIMDPP_PP_NODE_255(p) SIMDPP_PP_IIF(p(255), 255, 256)
#
# endif
