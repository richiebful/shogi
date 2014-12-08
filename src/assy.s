
./a.out:     file format elf64-x86-64


Disassembly of section .interp:

0000000000400238 <.interp>:
  400238:	2f                   	(bad)  
  400239:	6c                   	insb   (%dx),%es:(%rdi)
  40023a:	69 62 36 34 2f 6c 64 	imul   $0x646c2f34,0x36(%rdx),%esp
  400241:	2d 6c 69 6e 75       	sub    $0x756e696c,%eax
  400246:	78 2d                	js     400275 <_init-0x2c3>
  400248:	78 38                	js     400282 <_init-0x2b6>
  40024a:	36                   	ss
  40024b:	2d 36 34 2e 73       	sub    $0x732e3436,%eax
  400250:	6f                   	outsl  %ds:(%rsi),(%dx)
  400251:	2e 32 00             	xor    %cs:(%rax),%al

Disassembly of section .note.ABI-tag:

0000000000400254 <.note.ABI-tag>:
  400254:	04 00                	add    $0x0,%al
  400256:	00 00                	add    %al,(%rax)
  400258:	10 00                	adc    %al,(%rax)
  40025a:	00 00                	add    %al,(%rax)
  40025c:	01 00                	add    %eax,(%rax)
  40025e:	00 00                	add    %al,(%rax)
  400260:	47                   	rex.RXB
  400261:	4e 55                	rex.WRX push %rbp
  400263:	00 00                	add    %al,(%rax)
  400265:	00 00                	add    %al,(%rax)
  400267:	00 02                	add    %al,(%rdx)
  400269:	00 00                	add    %al,(%rax)
  40026b:	00 06                	add    %al,(%rsi)
  40026d:	00 00                	add    %al,(%rax)
  40026f:	00 18                	add    %bl,(%rax)
  400271:	00 00                	add    %al,(%rax)
	...

Disassembly of section .note.gnu.build-id:

0000000000400274 <.note.gnu.build-id>:
  400274:	04 00                	add    $0x0,%al
  400276:	00 00                	add    %al,(%rax)
  400278:	14 00                	adc    $0x0,%al
  40027a:	00 00                	add    %al,(%rax)
  40027c:	03 00                	add    (%rax),%eax
  40027e:	00 00                	add    %al,(%rax)
  400280:	47                   	rex.RXB
  400281:	4e 55                	rex.WRX push %rbp
  400283:	00 a6 5c 53 0a 9d    	add    %ah,-0x62f5aca4(%rsi)
  400289:	34 ff                	xor    $0xff,%al
  40028b:	14 b6                	adc    $0xb6,%al
  40028d:	6a 51                	pushq  $0x51
  40028f:	50                   	push   %rax
  400290:	e8 78 c5 6c e2       	callq  ffffffffe2acc80d <_end+0xffffffffe24c979d>
  400295:	e5 64                	in     $0x64,%eax
  400297:	af                   	scas   %es:(%rdi),%eax

Disassembly of section .gnu.hash:

0000000000400298 <.gnu.hash>:
  400298:	01 00                	add    %eax,(%rax)
  40029a:	00 00                	add    %al,(%rax)
  40029c:	01 00                	add    %eax,(%rax)
  40029e:	00 00                	add    %al,(%rax)
  4002a0:	01 00                	add    %eax,(%rax)
	...

Disassembly of section .dynsym:

00000000004002b8 <.dynsym>:
	...
  4002d0:	0b 00                	or     (%rax),%eax
  4002d2:	00 00                	add    %al,(%rax)
  4002d4:	12 00                	adc    (%rax),%al
	...
  4002e6:	00 00                	add    %al,(%rax)
  4002e8:	2e 00 00             	add    %al,%cs:(%rax)
  4002eb:	00 12                	add    %dl,(%rdx)
	...
  4002fd:	00 00                	add    %al,(%rax)
  4002ff:	00 37                	add    %dh,(%rdi)
  400301:	00 00                	add    %al,(%rax)
  400303:	00 12                	add    %dl,(%rdx)
	...
  400315:	00 00                	add    %al,(%rax)
  400317:	00 49 00             	add    %cl,0x0(%rcx)
  40031a:	00 00                	add    %al,(%rax)
  40031c:	20 00                	and    %al,(%rax)
	...
  40032e:	00 00                	add    %al,(%rax)
  400330:	12 00                	adc    (%rax),%al
  400332:	00 00                	add    %al,(%rax)
  400334:	12 00                	adc    (%rax),%al
	...
  400346:	00 00                	add    %al,(%rax)
  400348:	32 00                	xor    (%rax),%al
  40034a:	00 00                	add    %al,(%rax)
  40034c:	12 00                	adc    (%rax),%al
	...
  40035e:	00 00                	add    %al,(%rax)
  400360:	19 00                	sbb    %eax,(%rax)
  400362:	00 00                	add    %al,(%rax)
  400364:	12 00                	adc    (%rax),%al
	...
  400376:	00 00                	add    %al,(%rax)
  400378:	20 00                	and    %al,(%rax)
  40037a:	00 00                	add    %al,(%rax)
  40037c:	12 00                	adc    (%rax),%al
	...

Disassembly of section .dynstr:

0000000000400390 <.dynstr>:
  400390:	00 6c 69 62          	add    %ch,0x62(%rcx,%rbp,2)
  400394:	63 2e                	movslq (%rsi),%ebp
  400396:	73 6f                	jae    400407 <_init-0x131>
  400398:	2e 36 00 70 72       	cs add %dh,%cs:%ss:0x72(%rax)
  40039d:	69 6e 74 66 00 6d 65 	imul   $0x656d0066,0x74(%rsi),%ebp
  4003a4:	6d                   	insl   (%dx),%es:(%rdi)
  4003a5:	63 70 79             	movslq 0x79(%rax),%esi
  4003a8:	00 6d 61             	add    %ch,0x61(%rbp)
  4003ab:	6c                   	insb   (%dx),%es:(%rdi)
  4003ac:	6c                   	insb   (%dx),%es:(%rdi)
  4003ad:	6f                   	outsl  %ds:(%rsi),(%dx)
  4003ae:	63 00                	movslq (%rax),%eax
  4003b0:	5f                   	pop    %rdi
  4003b1:	5f                   	pop    %rdi
  4003b2:	63 74 79 70          	movslq 0x70(%rcx,%rdi,2),%esi
  4003b6:	65                   	gs
  4003b7:	5f                   	pop    %rdi
  4003b8:	62                   	(bad)  
  4003b9:	5f                   	pop    %rdi
  4003ba:	6c                   	insb   (%dx),%es:(%rdi)
  4003bb:	6f                   	outsl  %ds:(%rsi),(%dx)
  4003bc:	63 00                	movslq (%rax),%eax
  4003be:	64 69 66 66 74 69 6d 	imul   $0x656d6974,%fs:0x66(%rsi),%esp
  4003c5:	65 
  4003c6:	00 5f 5f             	add    %bl,0x5f(%rdi)
  4003c9:	6c                   	insb   (%dx),%es:(%rdi)
  4003ca:	69 62 63 5f 73 74 61 	imul   $0x6174735f,0x63(%rdx),%esp
  4003d1:	72 74                	jb     400447 <_init-0xf1>
  4003d3:	5f                   	pop    %rdi
  4003d4:	6d                   	insl   (%dx),%es:(%rdi)
  4003d5:	61                   	(bad)  
  4003d6:	69 6e 00 5f 5f 67 6d 	imul   $0x6d675f5f,0x0(%rsi),%ebp
  4003dd:	6f                   	outsl  %ds:(%rsi),(%dx)
  4003de:	6e                   	outsb  %ds:(%rsi),(%dx)
  4003df:	5f                   	pop    %rdi
  4003e0:	73 74                	jae    400456 <_init-0xe2>
  4003e2:	61                   	(bad)  
  4003e3:	72 74                	jb     400459 <_init-0xdf>
  4003e5:	5f                   	pop    %rdi
  4003e6:	5f                   	pop    %rdi
  4003e7:	00 47 4c             	add    %al,0x4c(%rdi)
  4003ea:	49                   	rex.WB
  4003eb:	42                   	rex.X
  4003ec:	43 5f                	rex.XB pop %r15
  4003ee:	32 2e                	xor    (%rsi),%ch
  4003f0:	33 00                	xor    (%rax),%eax
  4003f2:	47                   	rex.RXB
  4003f3:	4c                   	rex.WR
  4003f4:	49                   	rex.WB
  4003f5:	42                   	rex.X
  4003f6:	43 5f                	rex.XB pop %r15
  4003f8:	32 2e                	xor    (%rsi),%ch
  4003fa:	31 34 00             	xor    %esi,(%rax,%rax,1)
  4003fd:	47                   	rex.RXB
  4003fe:	4c                   	rex.WR
  4003ff:	49                   	rex.WB
  400400:	42                   	rex.X
  400401:	43 5f                	rex.XB pop %r15
  400403:	32 2e                	xor    (%rsi),%ch
  400405:	32 2e                	xor    (%rsi),%ch
  400407:	35                   	.byte 0x35
	...

Disassembly of section .gnu.version:

000000000040040a <.gnu.version>:
  40040a:	00 00                	add    %al,(%rax)
  40040c:	02 00                	add    (%rax),%al
  40040e:	02 00                	add    (%rax),%al
  400410:	02 00                	add    (%rax),%al
  400412:	00 00                	add    %al,(%rax)
  400414:	03 00                	add    (%rax),%eax
  400416:	02 00                	add    (%rax),%al
  400418:	02 00                	add    (%rax),%al
  40041a:	04 00                	add    $0x0,%al

Disassembly of section .gnu.version_r:

0000000000400420 <.gnu.version_r>:
  400420:	01 00                	add    %eax,(%rax)
  400422:	03 00                	add    (%rax),%eax
  400424:	01 00                	add    %eax,(%rax)
  400426:	00 00                	add    %al,(%rax)
  400428:	10 00                	adc    %al,(%rax)
  40042a:	00 00                	add    %al,(%rax)
  40042c:	00 00                	add    %al,(%rax)
  40042e:	00 00                	add    %al,(%rax)
  400430:	13 69 69             	adc    0x69(%rcx),%ebp
  400433:	0d 00 00 04 00       	or     $0x40000,%eax
  400438:	58                   	pop    %rax
  400439:	00 00                	add    %al,(%rax)
  40043b:	00 10                	add    %dl,(%rax)
  40043d:	00 00                	add    %al,(%rax)
  40043f:	00 94 91 96 06 00 00 	add    %dl,0x696(%rcx,%rdx,4)
  400446:	03 00                	add    (%rax),%eax
  400448:	62                   	(bad)  
  400449:	00 00                	add    %al,(%rax)
  40044b:	00 10                	add    %dl,(%rax)
  40044d:	00 00                	add    %al,(%rax)
  40044f:	00 75 1a             	add    %dh,0x1a(%rbp)
  400452:	69 09 00 00 02 00    	imul   $0x20000,(%rcx),%ecx
  400458:	6d                   	insl   (%dx),%es:(%rdi)
  400459:	00 00                	add    %al,(%rax)
  40045b:	00 00                	add    %al,(%rax)
  40045d:	00 00                	add    %al,(%rax)
	...

Disassembly of section .rela.dyn:

0000000000400460 <.rela.dyn>:
  400460:	f8                   	clc    
  400461:	2f                   	(bad)  
  400462:	60                   	(bad)  
  400463:	00 00                	add    %al,(%rax)
  400465:	00 00                	add    %al,(%rax)
  400467:	00 06                	add    %al,(%rsi)
  400469:	00 00                	add    %al,(%rax)
  40046b:	00 04 00             	add    %al,(%rax,%rax,1)
	...

Disassembly of section .rela.plt:

0000000000400478 <.rela.plt>:
  400478:	18 30                	sbb    %dh,(%rax)
  40047a:	60                   	(bad)  
  40047b:	00 00                	add    %al,(%rax)
  40047d:	00 00                	add    %al,(%rax)
  40047f:	00 07                	add    %al,(%rdi)
  400481:	00 00                	add    %al,(%rax)
  400483:	00 01                	add    %al,(%rcx)
	...
  40048d:	00 00                	add    %al,(%rax)
  40048f:	00 20                	add    %ah,(%rax)
  400491:	30 60 00             	xor    %ah,0x0(%rax)
  400494:	00 00                	add    %al,(%rax)
  400496:	00 00                	add    %al,(%rax)
  400498:	07                   	(bad)  
  400499:	00 00                	add    %al,(%rax)
  40049b:	00 02                	add    %al,(%rdx)
	...
  4004a5:	00 00                	add    %al,(%rax)
  4004a7:	00 28                	add    %ch,(%rax)
  4004a9:	30 60 00             	xor    %ah,0x0(%rax)
  4004ac:	00 00                	add    %al,(%rax)
  4004ae:	00 00                	add    %al,(%rax)
  4004b0:	07                   	(bad)  
  4004b1:	00 00                	add    %al,(%rax)
  4004b3:	00 03                	add    %al,(%rbx)
	...
  4004bd:	00 00                	add    %al,(%rax)
  4004bf:	00 30                	add    %dh,(%rax)
  4004c1:	30 60 00             	xor    %ah,0x0(%rax)
  4004c4:	00 00                	add    %al,(%rax)
  4004c6:	00 00                	add    %al,(%rax)
  4004c8:	07                   	(bad)  
  4004c9:	00 00                	add    %al,(%rax)
  4004cb:	00 04 00             	add    %al,(%rax,%rax,1)
	...
  4004d6:	00 00                	add    %al,(%rax)
  4004d8:	38 30                	cmp    %dh,(%rax)
  4004da:	60                   	(bad)  
  4004db:	00 00                	add    %al,(%rax)
  4004dd:	00 00                	add    %al,(%rax)
  4004df:	00 07                	add    %al,(%rdi)
  4004e1:	00 00                	add    %al,(%rax)
  4004e3:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 4004e9 <_init-0x4f>
  4004e9:	00 00                	add    %al,(%rax)
  4004eb:	00 00                	add    %al,(%rax)
  4004ed:	00 00                	add    %al,(%rax)
  4004ef:	00 40 30             	add    %al,0x30(%rax)
  4004f2:	60                   	(bad)  
  4004f3:	00 00                	add    %al,(%rax)
  4004f5:	00 00                	add    %al,(%rax)
  4004f7:	00 07                	add    %al,(%rdi)
  4004f9:	00 00                	add    %al,(%rax)
  4004fb:	00 06                	add    %al,(%rsi)
	...
  400505:	00 00                	add    %al,(%rax)
  400507:	00 48 30             	add    %cl,0x30(%rax)
  40050a:	60                   	(bad)  
  40050b:	00 00                	add    %al,(%rax)
  40050d:	00 00                	add    %al,(%rax)
  40050f:	00 07                	add    %al,(%rdi)
  400511:	00 00                	add    %al,(%rax)
  400513:	00 07                	add    %al,(%rdi)
	...
  40051d:	00 00                	add    %al,(%rax)
  40051f:	00 50 30             	add    %dl,0x30(%rax)
  400522:	60                   	(bad)  
  400523:	00 00                	add    %al,(%rax)
  400525:	00 00                	add    %al,(%rax)
  400527:	00 07                	add    %al,(%rdi)
  400529:	00 00                	add    %al,(%rax)
  40052b:	00 08                	add    %cl,(%rax)
	...

Disassembly of section .init:

0000000000400538 <_init>:
  400538:	48 83 ec 08          	sub    $0x8,%rsp
  40053c:	48 8b 05 b5 2a 20 00 	mov    0x202ab5(%rip),%rax        # 602ff8 <_DYNAMIC+0x1d0>
  400543:	48 85 c0             	test   %rax,%rax
  400546:	74 05                	je     40054d <_init+0x15>
  400548:	e8 53 00 00 00       	callq  4005a0 <__gmon_start__@plt>
  40054d:	48 83 c4 08          	add    $0x8,%rsp
  400551:	c3                   	retq   

Disassembly of section .plt:

0000000000400560 <printf@plt-0x10>:
  400560:	ff 35 a2 2a 20 00    	pushq  0x202aa2(%rip)        # 603008 <_GLOBAL_OFFSET_TABLE_+0x8>
  400566:	ff 25 a4 2a 20 00    	jmpq   *0x202aa4(%rip)        # 603010 <_GLOBAL_OFFSET_TABLE_+0x10>
  40056c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400570 <printf@plt>:
  400570:	ff 25 a2 2a 20 00    	jmpq   *0x202aa2(%rip)        # 603018 <_GLOBAL_OFFSET_TABLE_+0x18>
  400576:	68 00 00 00 00       	pushq  $0x0
  40057b:	e9 e0 ff ff ff       	jmpq   400560 <_init+0x28>

0000000000400580 <difftime@plt>:
  400580:	ff 25 9a 2a 20 00    	jmpq   *0x202a9a(%rip)        # 603020 <_GLOBAL_OFFSET_TABLE_+0x20>
  400586:	68 01 00 00 00       	pushq  $0x1
  40058b:	e9 d0 ff ff ff       	jmpq   400560 <_init+0x28>

0000000000400590 <__libc_start_main@plt>:
  400590:	ff 25 92 2a 20 00    	jmpq   *0x202a92(%rip)        # 603028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400596:	68 02 00 00 00       	pushq  $0x2
  40059b:	e9 c0 ff ff ff       	jmpq   400560 <_init+0x28>

00000000004005a0 <__gmon_start__@plt>:
  4005a0:	ff 25 8a 2a 20 00    	jmpq   *0x202a8a(%rip)        # 603030 <_GLOBAL_OFFSET_TABLE_+0x30>
  4005a6:	68 03 00 00 00       	pushq  $0x3
  4005ab:	e9 b0 ff ff ff       	jmpq   400560 <_init+0x28>

00000000004005b0 <memcpy@plt>:
  4005b0:	ff 25 82 2a 20 00    	jmpq   *0x202a82(%rip)        # 603038 <_GLOBAL_OFFSET_TABLE_+0x38>
  4005b6:	68 04 00 00 00       	pushq  $0x4
  4005bb:	e9 a0 ff ff ff       	jmpq   400560 <_init+0x28>

00000000004005c0 <time@plt>:
  4005c0:	ff 25 7a 2a 20 00    	jmpq   *0x202a7a(%rip)        # 603040 <_GLOBAL_OFFSET_TABLE_+0x40>
  4005c6:	68 05 00 00 00       	pushq  $0x5
  4005cb:	e9 90 ff ff ff       	jmpq   400560 <_init+0x28>

00000000004005d0 <malloc@plt>:
  4005d0:	ff 25 72 2a 20 00    	jmpq   *0x202a72(%rip)        # 603048 <_GLOBAL_OFFSET_TABLE_+0x48>
  4005d6:	68 06 00 00 00       	pushq  $0x6
  4005db:	e9 80 ff ff ff       	jmpq   400560 <_init+0x28>

00000000004005e0 <__ctype_b_loc@plt>:
  4005e0:	ff 25 6a 2a 20 00    	jmpq   *0x202a6a(%rip)        # 603050 <_GLOBAL_OFFSET_TABLE_+0x50>
  4005e6:	68 07 00 00 00       	pushq  $0x7
  4005eb:	e9 70 ff ff ff       	jmpq   400560 <_init+0x28>

Disassembly of section .text:

00000000004005f0 <_start>:
  4005f0:	31 ed                	xor    %ebp,%ebp
  4005f2:	49 89 d1             	mov    %rdx,%r9
  4005f5:	5e                   	pop    %rsi
  4005f6:	48 89 e2             	mov    %rsp,%rdx
  4005f9:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  4005fd:	50                   	push   %rax
  4005fe:	54                   	push   %rsp
  4005ff:	49 c7 c0 00 26 40 00 	mov    $0x402600,%r8
  400606:	48 c7 c1 90 25 40 00 	mov    $0x402590,%rcx
  40060d:	48 c7 c7 30 23 40 00 	mov    $0x402330,%rdi
  400614:	e8 77 ff ff ff       	callq  400590 <__libc_start_main@plt>
  400619:	f4                   	hlt    
  40061a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400620 <deregister_tm_clones>:
  400620:	b8 6f 30 60 00       	mov    $0x60306f,%eax
  400625:	55                   	push   %rbp
  400626:	48 2d 68 30 60 00    	sub    $0x603068,%rax
  40062c:	48 83 f8 0e          	cmp    $0xe,%rax
  400630:	48 89 e5             	mov    %rsp,%rbp
  400633:	77 02                	ja     400637 <deregister_tm_clones+0x17>
  400635:	5d                   	pop    %rbp
  400636:	c3                   	retq   
  400637:	b8 00 00 00 00       	mov    $0x0,%eax
  40063c:	48 85 c0             	test   %rax,%rax
  40063f:	74 f4                	je     400635 <deregister_tm_clones+0x15>
  400641:	5d                   	pop    %rbp
  400642:	bf 68 30 60 00       	mov    $0x603068,%edi
  400647:	ff e0                	jmpq   *%rax
  400649:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400650 <register_tm_clones>:
  400650:	b8 68 30 60 00       	mov    $0x603068,%eax
  400655:	55                   	push   %rbp
  400656:	48 2d 68 30 60 00    	sub    $0x603068,%rax
  40065c:	48 c1 f8 03          	sar    $0x3,%rax
  400660:	48 89 e5             	mov    %rsp,%rbp
  400663:	48 89 c2             	mov    %rax,%rdx
  400666:	48 c1 ea 3f          	shr    $0x3f,%rdx
  40066a:	48 01 d0             	add    %rdx,%rax
  40066d:	48 d1 f8             	sar    %rax
  400670:	75 02                	jne    400674 <register_tm_clones+0x24>
  400672:	5d                   	pop    %rbp
  400673:	c3                   	retq   
  400674:	ba 00 00 00 00       	mov    $0x0,%edx
  400679:	48 85 d2             	test   %rdx,%rdx
  40067c:	74 f4                	je     400672 <register_tm_clones+0x22>
  40067e:	5d                   	pop    %rbp
  40067f:	48 89 c6             	mov    %rax,%rsi
  400682:	bf 68 30 60 00       	mov    $0x603068,%edi
  400687:	ff e2                	jmpq   *%rdx
  400689:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000400690 <__do_global_dtors_aux>:
  400690:	80 3d d1 29 20 00 00 	cmpb   $0x0,0x2029d1(%rip)        # 603068 <__TMC_END__>
  400697:	75 11                	jne    4006aa <__do_global_dtors_aux+0x1a>
  400699:	55                   	push   %rbp
  40069a:	48 89 e5             	mov    %rsp,%rbp
  40069d:	e8 7e ff ff ff       	callq  400620 <deregister_tm_clones>
  4006a2:	5d                   	pop    %rbp
  4006a3:	c6 05 be 29 20 00 01 	movb   $0x1,0x2029be(%rip)        # 603068 <__TMC_END__>
  4006aa:	f3 c3                	repz retq 
  4006ac:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004006b0 <frame_dummy>:
  4006b0:	48 83 3d 68 27 20 00 	cmpq   $0x0,0x202768(%rip)        # 602e20 <__JCR_END__>
  4006b7:	00 
  4006b8:	74 1e                	je     4006d8 <frame_dummy+0x28>
  4006ba:	b8 00 00 00 00       	mov    $0x0,%eax
  4006bf:	48 85 c0             	test   %rax,%rax
  4006c2:	74 14                	je     4006d8 <frame_dummy+0x28>
  4006c4:	55                   	push   %rbp
  4006c5:	bf 20 2e 60 00       	mov    $0x602e20,%edi
  4006ca:	48 89 e5             	mov    %rsp,%rbp
  4006cd:	ff d0                	callq  *%rax
  4006cf:	5d                   	pop    %rbp
  4006d0:	e9 7b ff ff ff       	jmpq   400650 <register_tm_clones>
  4006d5:	0f 1f 00             	nopl   (%rax)
  4006d8:	e9 73 ff ff ff       	jmpq   400650 <register_tm_clones>
  4006dd:	0f 1f 00             	nopl   (%rax)

00000000004006e0 <legalmove>:
  4006e0:	55                   	push   %rbp
  4006e1:	48 89 e5             	mov    %rsp,%rbp
  4006e4:	48 81 ec e0 03 00 00 	sub    $0x3e0,%rsp
  4006eb:	b8 08 00 00 00       	mov    $0x8,%eax
  4006f0:	48 89 7d f0          	mov    %rdi,-0x10(%rbp)
  4006f4:	89 75 ec             	mov    %esi,-0x14(%rbp)
  4006f7:	48 89 55 e0          	mov    %rdx,-0x20(%rbp)
  4006fb:	48 89 4d d8          	mov    %rcx,-0x28(%rbp)
  4006ff:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  400703:	8b 31                	mov    (%rcx),%esi
  400705:	89 75 d4             	mov    %esi,-0x2c(%rbp)
  400708:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  40070c:	89 c6                	mov    %eax,%esi
  40070e:	2b 71 04             	sub    0x4(%rcx),%esi
  400711:	89 75 d0             	mov    %esi,-0x30(%rbp)
  400714:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
  400718:	8b 31                	mov    (%rcx),%esi
  40071a:	89 75 cc             	mov    %esi,-0x34(%rbp)
  40071d:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
  400721:	2b 41 04             	sub    0x4(%rcx),%eax
  400724:	89 45 c8             	mov    %eax,-0x38(%rbp)
  400727:	81 7d ec 01 00 00 00 	cmpl   $0x1,-0x14(%rbp)
  40072e:	0f 85 24 00 00 00    	jne    400758 <legalmove+0x78>
  400734:	b8 08 00 00 00       	mov    $0x8,%eax
  400739:	89 c1                	mov    %eax,%ecx
  40073b:	2b 4d d4             	sub    -0x2c(%rbp),%ecx
  40073e:	89 4d c4             	mov    %ecx,-0x3c(%rbp)
  400741:	2b 45 cc             	sub    -0x34(%rbp),%eax
  400744:	89 45 bc             	mov    %eax,-0x44(%rbp)
  400747:	8b 45 d0             	mov    -0x30(%rbp),%eax
  40074a:	89 45 c0             	mov    %eax,-0x40(%rbp)
  40074d:	8b 45 c8             	mov    -0x38(%rbp),%eax
  400750:	89 45 b8             	mov    %eax,-0x48(%rbp)
  400753:	e9 1f 00 00 00       	jmpq   400777 <legalmove+0x97>
  400758:	b8 08 00 00 00       	mov    $0x8,%eax
  40075d:	8b 4d d4             	mov    -0x2c(%rbp),%ecx
  400760:	89 4d c4             	mov    %ecx,-0x3c(%rbp)
  400763:	8b 4d cc             	mov    -0x34(%rbp),%ecx
  400766:	89 4d bc             	mov    %ecx,-0x44(%rbp)
  400769:	89 c1                	mov    %eax,%ecx
  40076b:	2b 4d d0             	sub    -0x30(%rbp),%ecx
  40076e:	89 4d c0             	mov    %ecx,-0x40(%rbp)
  400771:	2b 45 c8             	sub    -0x38(%rbp),%eax
  400774:	89 45 b8             	mov    %eax,-0x48(%rbp)
  400777:	48 8d 85 88 fe ff ff 	lea    -0x178(%rbp),%rax
  40077e:	48 ba d8 00 00 00 00 	movabs $0xd8,%rdx
  400785:	00 00 00 
  400788:	48 b9 51 00 00 00 00 	movabs $0x51,%rcx
  40078f:	00 00 00 
  400792:	48 8d b5 60 ff ff ff 	lea    -0xa0(%rbp),%rsi
  400799:	48 8b 7d f0          	mov    -0x10(%rbp),%rdi
  40079d:	48 89 bd 48 fd ff ff 	mov    %rdi,-0x2b8(%rbp)
  4007a4:	48 89 f7             	mov    %rsi,%rdi
  4007a7:	48 8b b5 48 fd ff ff 	mov    -0x2b8(%rbp),%rsi
  4007ae:	48 89 95 40 fd ff ff 	mov    %rdx,-0x2c0(%rbp)
  4007b5:	48 89 ca             	mov    %rcx,%rdx
  4007b8:	48 89 85 38 fd ff ff 	mov    %rax,-0x2c8(%rbp)
  4007bf:	e8 ec fd ff ff       	callq  4005b0 <memcpy@plt>
  4007c4:	48 8b 85 38 fd ff ff 	mov    -0x2c8(%rbp),%rax
  4007cb:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  4007cf:	48 89 c7             	mov    %rax,%rdi
  4007d2:	48 89 ce             	mov    %rcx,%rsi
  4007d5:	48 8b 95 40 fd ff ff 	mov    -0x2c0(%rbp),%rdx
  4007dc:	e8 cf fd ff ff       	callq  4005b0 <memcpy@plt>
  4007e1:	8b 75 ec             	mov    -0x14(%rbp),%esi
  4007e4:	48 8b 55 e0          	mov    -0x20(%rbp),%rdx
  4007e8:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
  4007ec:	48 8b bd 38 fd ff ff 	mov    -0x2c8(%rbp),%rdi
  4007f3:	e8 b8 13 00 00       	callq  401bb0 <mkmove>
  4007f8:	48 8d 85 60 ff ff ff 	lea    -0xa0(%rbp),%rax
  4007ff:	48 63 4d d0          	movslq -0x30(%rbp),%rcx
  400803:	48 63 55 d4          	movslq -0x2c(%rbp),%rdx
  400807:	48 69 d2 09 00 00 00 	imul   $0x9,%rdx,%rdx
  40080e:	48 01 d0             	add    %rdx,%rax
  400811:	44 8a 04 08          	mov    (%rax,%rcx,1),%r8b
  400815:	44 88 85 87 fe ff ff 	mov    %r8b,-0x179(%rbp)
  40081c:	48 8b 7d f0          	mov    -0x10(%rbp),%rdi
  400820:	8b 75 ec             	mov    -0x14(%rbp),%esi
  400823:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  400827:	8b 10                	mov    (%rax),%edx
  400829:	48 8b 45 d8          	mov    -0x28(%rbp),%rax
  40082d:	8b 48 04             	mov    0x4(%rax),%ecx
  400830:	e8 ab 0e 00 00       	callq  4016e0 <legaldest>
  400835:	3d 00 00 00 00       	cmp    $0x0,%eax
  40083a:	0f 85 21 00 00 00    	jne    400861 <legalmove+0x181>
  400840:	48 8d 3c 25 14 26 40 	lea    0x402614,%rdi
  400847:	00 
  400848:	b0 00                	mov    $0x0,%al
  40084a:	e8 21 fd ff ff       	callq  400570 <printf@plt>
  40084f:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  400856:	89 85 34 fd ff ff    	mov    %eax,-0x2cc(%rbp)
  40085c:	e9 6a 0e 00 00       	jmpq   4016cb <legalmove+0xfeb>
  400861:	48 8b 7d f0          	mov    -0x10(%rbp),%rdi
  400865:	8b 75 ec             	mov    -0x14(%rbp),%esi
  400868:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  40086c:	8b 10                	mov    (%rax),%edx
  40086e:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  400872:	8b 48 04             	mov    0x4(%rax),%ecx
  400875:	e8 86 0f 00 00       	callq  401800 <legalsrc>
  40087a:	3d 00 00 00 00       	cmp    $0x0,%eax
  40087f:	0f 85 21 00 00 00    	jne    4008a6 <legalmove+0x1c6>
  400885:	48 8d 3c 25 20 26 40 	lea    0x402620,%rdi
  40088c:	00 
  40088d:	b0 00                	mov    $0x0,%al
  40088f:	e8 dc fc ff ff       	callq  400570 <printf@plt>
  400894:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  40089b:	89 85 30 fd ff ff    	mov    %eax,-0x2d0(%rbp)
  4008a1:	e9 25 0e 00 00       	jmpq   4016cb <legalmove+0xfeb>
  4008a6:	8b 45 cc             	mov    -0x34(%rbp),%eax
  4008a9:	3b 45 d4             	cmp    -0x2c(%rbp),%eax
  4008ac:	0f 85 2d 00 00 00    	jne    4008df <legalmove+0x1ff>
  4008b2:	8b 45 c8             	mov    -0x38(%rbp),%eax
  4008b5:	3b 45 d0             	cmp    -0x30(%rbp),%eax
  4008b8:	0f 85 21 00 00 00    	jne    4008df <legalmove+0x1ff>
  4008be:	48 8d 3c 25 2b 26 40 	lea    0x40262b,%rdi
  4008c5:	00 
  4008c6:	b0 00                	mov    $0x0,%al
  4008c8:	e8 a3 fc ff ff       	callq  400570 <printf@plt>
  4008cd:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  4008d4:	89 85 2c fd ff ff    	mov    %eax,-0x2d4(%rbp)
  4008da:	e9 ec 0d 00 00       	jmpq   4016cb <legalmove+0xfeb>
  4008df:	8b 7d ec             	mov    -0x14(%rbp),%edi
  4008e2:	48 89 e0             	mov    %rsp,%rax
  4008e5:	b9 1b 00 00 00       	mov    $0x1b,%ecx
  4008ea:	48 8d b5 88 fe ff ff 	lea    -0x178(%rbp),%rsi
  4008f1:	89 bd 28 fd ff ff    	mov    %edi,-0x2d8(%rbp)
  4008f7:	48 89 c7             	mov    %rax,%rdi
  4008fa:	f3 48 a5             	rep movsq %ds:(%rsi),%es:(%rdi)
  4008fd:	8b bd 28 fd ff ff    	mov    -0x2d8(%rbp),%edi
  400903:	e8 a8 15 00 00       	callq  401eb0 <ischeck>
  400908:	3d 00 00 00 00       	cmp    $0x0,%eax
  40090d:	0f 84 21 00 00 00    	je     400934 <legalmove+0x254>
  400913:	48 8d 3c 25 37 26 40 	lea    0x402637,%rdi
  40091a:	00 
  40091b:	b0 00                	mov    $0x0,%al
  40091d:	e8 4e fc ff ff       	callq  400570 <printf@plt>
  400922:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  400929:	89 85 24 fd ff ff    	mov    %eax,-0x2dc(%rbp)
  40092f:	e9 97 0d 00 00       	jmpq   4016cb <legalmove+0xfeb>
  400934:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  40093b:	3d 50 00 00 00       	cmp    $0x50,%eax
  400940:	0f 84 12 00 00 00    	je     400958 <legalmove+0x278>
  400946:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  40094d:	3d 70 00 00 00       	cmp    $0x70,%eax
  400952:	0f 85 4a 00 00 00    	jne    4009a2 <legalmove+0x2c2>
  400958:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  40095b:	05 01 00 00 00       	add    $0x1,%eax
  400960:	3b 45 bc             	cmp    -0x44(%rbp),%eax
  400963:	0f 85 18 00 00 00    	jne    400981 <legalmove+0x2a1>
  400969:	8b 45 c0             	mov    -0x40(%rbp),%eax
  40096c:	3b 45 b8             	cmp    -0x48(%rbp),%eax
  40096f:	0f 85 0c 00 00 00    	jne    400981 <legalmove+0x2a1>
  400975:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  40097c:	e9 4a 0d 00 00       	jmpq   4016cb <legalmove+0xfeb>
  400981:	48 8d 3c 25 51 26 40 	lea    0x402651,%rdi
  400988:	00 
  400989:	b0 00                	mov    $0x0,%al
  40098b:	e8 e0 fb ff ff       	callq  400570 <printf@plt>
  400990:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  400997:	89 85 20 fd ff ff    	mov    %eax,-0x2e0(%rbp)
  40099d:	e9 29 0d 00 00       	jmpq   4016cb <legalmove+0xfeb>
  4009a2:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  4009a9:	3d 52 00 00 00       	cmp    $0x52,%eax
  4009ae:	0f 84 36 00 00 00    	je     4009ea <legalmove+0x30a>
  4009b4:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  4009bb:	3d 72 00 00 00       	cmp    $0x72,%eax
  4009c0:	0f 84 24 00 00 00    	je     4009ea <legalmove+0x30a>
  4009c6:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  4009cd:	3d 53 00 00 00       	cmp    $0x53,%eax
  4009d2:	0f 84 12 00 00 00    	je     4009ea <legalmove+0x30a>
  4009d8:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  4009df:	3d 73 00 00 00       	cmp    $0x73,%eax
  4009e4:	0f 85 7a 03 00 00    	jne    400d64 <legalmove+0x684>
  4009ea:	48 8d 3c 25 5a 26 40 	lea    0x40265a,%rdi
  4009f1:	00 
  4009f2:	b0 00                	mov    $0x0,%al
  4009f4:	e8 77 fb ff ff       	callq  400570 <printf@plt>
  4009f9:	c7 85 7c fe ff ff 01 	movl   $0x1,-0x184(%rbp)
  400a00:	00 00 00 
  400a03:	8b 4d cc             	mov    -0x34(%rbp),%ecx
  400a06:	3b 4d d4             	cmp    -0x2c(%rbp),%ecx
  400a09:	89 85 1c fd ff ff    	mov    %eax,-0x2e4(%rbp)
  400a0f:	0f 84 0c 00 00 00    	je     400a21 <legalmove+0x341>
  400a15:	8b 45 c8             	mov    -0x38(%rbp),%eax
  400a18:	3b 45 d0             	cmp    -0x30(%rbp),%eax
  400a1b:	0f 84 27 00 00 00    	je     400a48 <legalmove+0x368>
  400a21:	8b 45 cc             	mov    -0x34(%rbp),%eax
  400a24:	3b 45 d4             	cmp    -0x2c(%rbp),%eax
  400a27:	0f 85 0c 00 00 00    	jne    400a39 <legalmove+0x359>
  400a2d:	8b 45 c8             	mov    -0x38(%rbp),%eax
  400a30:	3b 45 d0             	cmp    -0x30(%rbp),%eax
  400a33:	0f 85 0f 00 00 00    	jne    400a48 <legalmove+0x368>
  400a39:	c7 85 7c fe ff ff 00 	movl   $0x0,-0x184(%rbp)
  400a40:	00 00 00 
  400a43:	e9 0e 02 00 00       	jmpq   400c56 <legalmove+0x576>
  400a48:	8b 45 cc             	mov    -0x34(%rbp),%eax
  400a4b:	3b 45 d4             	cmp    -0x2c(%rbp),%eax
  400a4e:	0f 8e 78 00 00 00    	jle    400acc <legalmove+0x3ec>
  400a54:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  400a57:	05 01 00 00 00       	add    $0x1,%eax
  400a5c:	89 85 80 fe ff ff    	mov    %eax,-0x180(%rbp)
  400a62:	8b 85 80 fe ff ff    	mov    -0x180(%rbp),%eax
  400a68:	3b 45 cc             	cmp    -0x34(%rbp),%eax
  400a6b:	0f 84 56 00 00 00    	je     400ac7 <legalmove+0x3e7>
  400a71:	48 8d 85 60 ff ff ff 	lea    -0xa0(%rbp),%rax
  400a78:	48 63 4d d0          	movslq -0x30(%rbp),%rcx
  400a7c:	48 63 95 80 fe ff ff 	movslq -0x180(%rbp),%rdx
  400a83:	48 69 d2 09 00 00 00 	imul   $0x9,%rdx,%rdx
  400a8a:	48 01 d0             	add    %rdx,%rax
  400a8d:	0f be 34 08          	movsbl (%rax,%rcx,1),%esi
  400a91:	81 fe 20 00 00 00    	cmp    $0x20,%esi
  400a97:	0f 84 0f 00 00 00    	je     400aac <legalmove+0x3cc>
  400a9d:	c7 85 7c fe ff ff 00 	movl   $0x0,-0x184(%rbp)
  400aa4:	00 00 00 
  400aa7:	e9 1b 00 00 00       	jmpq   400ac7 <legalmove+0x3e7>
  400aac:	e9 00 00 00 00       	jmpq   400ab1 <legalmove+0x3d1>
  400ab1:	8b 85 80 fe ff ff    	mov    -0x180(%rbp),%eax
  400ab7:	05 01 00 00 00       	add    $0x1,%eax
  400abc:	89 85 80 fe ff ff    	mov    %eax,-0x180(%rbp)
  400ac2:	e9 9b ff ff ff       	jmpq   400a62 <legalmove+0x382>
  400ac7:	e9 85 01 00 00       	jmpq   400c51 <legalmove+0x571>
  400acc:	8b 45 cc             	mov    -0x34(%rbp),%eax
  400acf:	3b 45 d4             	cmp    -0x2c(%rbp),%eax
  400ad2:	0f 8d 78 00 00 00    	jge    400b50 <legalmove+0x470>
  400ad8:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  400adb:	2d 01 00 00 00       	sub    $0x1,%eax
  400ae0:	89 85 80 fe ff ff    	mov    %eax,-0x180(%rbp)
  400ae6:	8b 85 80 fe ff ff    	mov    -0x180(%rbp),%eax
  400aec:	3b 45 cc             	cmp    -0x34(%rbp),%eax
  400aef:	0f 84 56 00 00 00    	je     400b4b <legalmove+0x46b>
  400af5:	48 8d 85 60 ff ff ff 	lea    -0xa0(%rbp),%rax
  400afc:	48 63 4d d0          	movslq -0x30(%rbp),%rcx
  400b00:	48 63 95 80 fe ff ff 	movslq -0x180(%rbp),%rdx
  400b07:	48 69 d2 09 00 00 00 	imul   $0x9,%rdx,%rdx
  400b0e:	48 01 d0             	add    %rdx,%rax
  400b11:	0f be 34 08          	movsbl (%rax,%rcx,1),%esi
  400b15:	81 fe 20 00 00 00    	cmp    $0x20,%esi
  400b1b:	0f 84 0f 00 00 00    	je     400b30 <legalmove+0x450>
  400b21:	c7 85 7c fe ff ff 00 	movl   $0x0,-0x184(%rbp)
  400b28:	00 00 00 
  400b2b:	e9 1b 00 00 00       	jmpq   400b4b <legalmove+0x46b>
  400b30:	e9 00 00 00 00       	jmpq   400b35 <legalmove+0x455>
  400b35:	8b 85 80 fe ff ff    	mov    -0x180(%rbp),%eax
  400b3b:	05 ff ff ff ff       	add    $0xffffffff,%eax
  400b40:	89 85 80 fe ff ff    	mov    %eax,-0x180(%rbp)
  400b46:	e9 9b ff ff ff       	jmpq   400ae6 <legalmove+0x406>
  400b4b:	e9 fc 00 00 00       	jmpq   400c4c <legalmove+0x56c>
  400b50:	8b 45 c8             	mov    -0x38(%rbp),%eax
  400b53:	3b 45 d0             	cmp    -0x30(%rbp),%eax
  400b56:	0f 8e 78 00 00 00    	jle    400bd4 <legalmove+0x4f4>
  400b5c:	8b 45 d0             	mov    -0x30(%rbp),%eax
  400b5f:	05 01 00 00 00       	add    $0x1,%eax
  400b64:	89 85 80 fe ff ff    	mov    %eax,-0x180(%rbp)
  400b6a:	8b 85 80 fe ff ff    	mov    -0x180(%rbp),%eax
  400b70:	3b 45 c8             	cmp    -0x38(%rbp),%eax
  400b73:	0f 84 56 00 00 00    	je     400bcf <legalmove+0x4ef>
  400b79:	48 8d 85 60 ff ff ff 	lea    -0xa0(%rbp),%rax
  400b80:	48 63 8d 80 fe ff ff 	movslq -0x180(%rbp),%rcx
  400b87:	48 63 55 d4          	movslq -0x2c(%rbp),%rdx
  400b8b:	48 69 d2 09 00 00 00 	imul   $0x9,%rdx,%rdx
  400b92:	48 01 d0             	add    %rdx,%rax
  400b95:	0f be 34 08          	movsbl (%rax,%rcx,1),%esi
  400b99:	81 fe 20 00 00 00    	cmp    $0x20,%esi
  400b9f:	0f 84 0f 00 00 00    	je     400bb4 <legalmove+0x4d4>
  400ba5:	c7 85 7c fe ff ff 00 	movl   $0x0,-0x184(%rbp)
  400bac:	00 00 00 
  400baf:	e9 1b 00 00 00       	jmpq   400bcf <legalmove+0x4ef>
  400bb4:	e9 00 00 00 00       	jmpq   400bb9 <legalmove+0x4d9>
  400bb9:	8b 85 80 fe ff ff    	mov    -0x180(%rbp),%eax
  400bbf:	05 01 00 00 00       	add    $0x1,%eax
  400bc4:	89 85 80 fe ff ff    	mov    %eax,-0x180(%rbp)
  400bca:	e9 9b ff ff ff       	jmpq   400b6a <legalmove+0x48a>
  400bcf:	e9 73 00 00 00       	jmpq   400c47 <legalmove+0x567>
  400bd4:	8b 45 d0             	mov    -0x30(%rbp),%eax
  400bd7:	2d 01 00 00 00       	sub    $0x1,%eax
  400bdc:	89 85 80 fe ff ff    	mov    %eax,-0x180(%rbp)
  400be2:	8b 85 80 fe ff ff    	mov    -0x180(%rbp),%eax
  400be8:	3b 45 c8             	cmp    -0x38(%rbp),%eax
  400beb:	0f 84 51 00 00 00    	je     400c42 <legalmove+0x562>
  400bf1:	48 8d 85 60 ff ff ff 	lea    -0xa0(%rbp),%rax
  400bf8:	48 63 8d 80 fe ff ff 	movslq -0x180(%rbp),%rcx
  400bff:	48 63 55 d4          	movslq -0x2c(%rbp),%rdx
  400c03:	48 69 d2 09 00 00 00 	imul   $0x9,%rdx,%rdx
  400c0a:	48 01 d0             	add    %rdx,%rax
  400c0d:	0f be 34 08          	movsbl (%rax,%rcx,1),%esi
  400c11:	81 fe 20 00 00 00    	cmp    $0x20,%esi
  400c17:	0f 84 0a 00 00 00    	je     400c27 <legalmove+0x547>
  400c1d:	c7 85 7c fe ff ff 00 	movl   $0x0,-0x184(%rbp)
  400c24:	00 00 00 
  400c27:	e9 00 00 00 00       	jmpq   400c2c <legalmove+0x54c>
  400c2c:	8b 85 80 fe ff ff    	mov    -0x180(%rbp),%eax
  400c32:	05 ff ff ff ff       	add    $0xffffffff,%eax
  400c37:	89 85 80 fe ff ff    	mov    %eax,-0x180(%rbp)
  400c3d:	e9 a0 ff ff ff       	jmpq   400be2 <legalmove+0x502>
  400c42:	e9 00 00 00 00       	jmpq   400c47 <legalmove+0x567>
  400c47:	e9 00 00 00 00       	jmpq   400c4c <legalmove+0x56c>
  400c4c:	e9 00 00 00 00       	jmpq   400c51 <legalmove+0x571>
  400c51:	e9 00 00 00 00       	jmpq   400c56 <legalmove+0x576>
  400c56:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  400c5d:	3d 52 00 00 00       	cmp    $0x52,%eax
  400c62:	0f 84 12 00 00 00    	je     400c7a <legalmove+0x59a>
  400c68:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  400c6f:	3d 72 00 00 00       	cmp    $0x72,%eax
  400c74:	0f 85 0e 00 00 00    	jne    400c88 <legalmove+0x5a8>
  400c7a:	8b 85 7c fe ff ff    	mov    -0x184(%rbp),%eax
  400c80:	89 45 fc             	mov    %eax,-0x4(%rbp)
  400c83:	e9 43 0a 00 00       	jmpq   4016cb <legalmove+0xfeb>
  400c88:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  400c8b:	05 01 00 00 00       	add    $0x1,%eax
  400c90:	89 85 50 fe ff ff    	mov    %eax,-0x1b0(%rbp)
  400c96:	8b 45 d0             	mov    -0x30(%rbp),%eax
  400c99:	89 85 54 fe ff ff    	mov    %eax,-0x1ac(%rbp)
  400c9f:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  400ca2:	2d 01 00 00 00       	sub    $0x1,%eax
  400ca7:	89 85 58 fe ff ff    	mov    %eax,-0x1a8(%rbp)
  400cad:	8b 45 d0             	mov    -0x30(%rbp),%eax
  400cb0:	89 85 5c fe ff ff    	mov    %eax,-0x1a4(%rbp)
  400cb6:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  400cb9:	89 85 60 fe ff ff    	mov    %eax,-0x1a0(%rbp)
  400cbf:	8b 45 d0             	mov    -0x30(%rbp),%eax
  400cc2:	05 01 00 00 00       	add    $0x1,%eax
  400cc7:	89 85 64 fe ff ff    	mov    %eax,-0x19c(%rbp)
  400ccd:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  400cd0:	89 85 68 fe ff ff    	mov    %eax,-0x198(%rbp)
  400cd6:	8b 45 d0             	mov    -0x30(%rbp),%eax
  400cd9:	2d 01 00 00 00       	sub    $0x1,%eax
  400cde:	89 85 6c fe ff ff    	mov    %eax,-0x194(%rbp)
  400ce4:	c7 85 78 fe ff ff 00 	movl   $0x0,-0x188(%rbp)
  400ceb:	00 00 00 
  400cee:	48 63 85 78 fe ff ff 	movslq -0x188(%rbp),%rax
  400cf5:	48 3d 04 00 00 00    	cmp    $0x4,%rax
  400cfb:	0f 83 55 00 00 00    	jae    400d56 <legalmove+0x676>
  400d01:	48 63 85 78 fe ff ff 	movslq -0x188(%rbp),%rax
  400d08:	8b 8c c5 50 fe ff ff 	mov    -0x1b0(%rbp,%rax,8),%ecx
  400d0f:	3b 4d cc             	cmp    -0x34(%rbp),%ecx
  400d12:	0f 85 23 00 00 00    	jne    400d3b <legalmove+0x65b>
  400d18:	48 63 85 78 fe ff ff 	movslq -0x188(%rbp),%rax
  400d1f:	8b 8c c5 54 fe ff ff 	mov    -0x1ac(%rbp,%rax,8),%ecx
  400d26:	3b 4d c8             	cmp    -0x38(%rbp),%ecx
  400d29:	0f 85 0c 00 00 00    	jne    400d3b <legalmove+0x65b>
  400d2f:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  400d36:	e9 90 09 00 00       	jmpq   4016cb <legalmove+0xfeb>
  400d3b:	e9 00 00 00 00       	jmpq   400d40 <legalmove+0x660>
  400d40:	8b 85 78 fe ff ff    	mov    -0x188(%rbp),%eax
  400d46:	05 01 00 00 00       	add    $0x1,%eax
  400d4b:	89 85 78 fe ff ff    	mov    %eax,-0x188(%rbp)
  400d51:	e9 98 ff ff ff       	jmpq   400cee <legalmove+0x60e>
  400d56:	8b 85 7c fe ff ff    	mov    -0x184(%rbp),%eax
  400d5c:	89 45 fc             	mov    %eax,-0x4(%rbp)
  400d5f:	e9 67 09 00 00       	jmpq   4016cb <legalmove+0xfeb>
  400d64:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  400d6b:	3d 42 00 00 00       	cmp    $0x42,%eax
  400d70:	0f 84 36 00 00 00    	je     400dac <legalmove+0x6cc>
  400d76:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  400d7d:	3d 62 00 00 00       	cmp    $0x62,%eax
  400d82:	0f 84 24 00 00 00    	je     400dac <legalmove+0x6cc>
  400d88:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  400d8f:	3d 43 00 00 00       	cmp    $0x43,%eax
  400d94:	0f 84 12 00 00 00    	je     400dac <legalmove+0x6cc>
  400d9a:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  400da1:	3d 63 00 00 00       	cmp    $0x63,%eax
  400da6:	0f 85 5b 03 00 00    	jne    401107 <legalmove+0xa27>
  400dac:	48 b8 01 00 00 00 00 	movabs $0x1,%rax
  400db3:	00 00 00 
  400db6:	f2 48 0f 2a c0       	cvtsi2sd %rax,%xmm0
  400dbb:	c6 85 3f fe ff ff 00 	movb   $0x0,-0x1c1(%rbp)
  400dc2:	8b 4d cc             	mov    -0x34(%rbp),%ecx
  400dc5:	2b 4d d4             	sub    -0x2c(%rbp),%ecx
  400dc8:	8b 55 c8             	mov    -0x38(%rbp),%edx
  400dcb:	2b 55 d0             	sub    -0x30(%rbp),%edx
  400dce:	89 c8                	mov    %ecx,%eax
  400dd0:	89 95 18 fd ff ff    	mov    %edx,-0x2e8(%rbp)
  400dd6:	99                   	cltd   
  400dd7:	8b 8d 18 fd ff ff    	mov    -0x2e8(%rbp),%ecx
  400ddd:	f7 f9                	idiv   %ecx
  400ddf:	f2 0f 2a c8          	cvtsi2sd %eax,%xmm1
  400de3:	f2 0f 11 8d 48 fe ff 	movsd  %xmm1,-0x1b8(%rbp)
  400dea:	ff 
  400deb:	f2 0f 10 8d 48 fe ff 	movsd  -0x1b8(%rbp),%xmm1
  400df2:	ff 
  400df3:	66 0f 2e c8          	ucomisd %xmm0,%xmm1
  400df7:	0f 85 0b 00 00 00    	jne    400e08 <legalmove+0x728>
  400dfd:	0f 8a 05 00 00 00    	jp     400e08 <legalmove+0x728>
  400e03:	e9 4d 00 00 00       	jmpq   400e55 <legalmove+0x775>
  400e08:	48 b8 ff ff ff ff ff 	movabs $0xffffffffffffffff,%rax
  400e0f:	ff ff ff 
  400e12:	f2 48 0f 2a c0       	cvtsi2sd %rax,%xmm0
  400e17:	f2 0f 10 8d 48 fe ff 	movsd  -0x1b8(%rbp),%xmm1
  400e1e:	ff 
  400e1f:	66 0f 2e c8          	ucomisd %xmm0,%xmm1
  400e23:	0f 85 0b 00 00 00    	jne    400e34 <legalmove+0x754>
  400e29:	0f 8a 05 00 00 00    	jp     400e34 <legalmove+0x754>
  400e2f:	e9 21 00 00 00       	jmpq   400e55 <legalmove+0x775>
  400e34:	48 8d 3c 25 67 26 40 	lea    0x402667,%rdi
  400e3b:	00 
  400e3c:	b0 00                	mov    $0x0,%al
  400e3e:	e8 2d f7 ff ff       	callq  400570 <printf@plt>
  400e43:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  400e4a:	89 85 14 fd ff ff    	mov    %eax,-0x2ec(%rbp)
  400e50:	e9 76 08 00 00       	jmpq   4016cb <legalmove+0xfeb>
  400e55:	8b 45 c8             	mov    -0x38(%rbp),%eax
  400e58:	3b 45 d0             	cmp    -0x30(%rbp),%eax
  400e5b:	0f 8d 1c 00 00 00    	jge    400e7d <legalmove+0x79d>
  400e61:	48 b8 ff ff ff ff ff 	movabs $0xffffffffffffffff,%rax
  400e68:	ff ff ff 
  400e6b:	f2 48 0f 2a c0       	cvtsi2sd %rax,%xmm0
  400e70:	f2 0f 11 85 40 fe ff 	movsd  %xmm0,-0x1c0(%rbp)
  400e77:	ff 
  400e78:	e9 17 00 00 00       	jmpq   400e94 <legalmove+0x7b4>
  400e7d:	48 b8 01 00 00 00 00 	movabs $0x1,%rax
  400e84:	00 00 00 
  400e87:	f2 48 0f 2a c0       	cvtsi2sd %rax,%xmm0
  400e8c:	f2 0f 11 85 40 fe ff 	movsd  %xmm0,-0x1c0(%rbp)
  400e93:	ff 
  400e94:	e9 00 00 00 00       	jmpq   400e99 <legalmove+0x7b9>
  400e99:	48 8d 3c 25 73 26 40 	lea    0x402673,%rdi
  400ea0:	00 
  400ea1:	8b 75 d4             	mov    -0x2c(%rbp),%esi
  400ea4:	8b 55 d0             	mov    -0x30(%rbp),%edx
  400ea7:	b0 00                	mov    $0x0,%al
  400ea9:	e8 c2 f6 ff ff       	callq  400570 <printf@plt>
  400eae:	48 8d 3c 25 7f 26 40 	lea    0x40267f,%rdi
  400eb5:	00 
  400eb6:	f2 0f 2a 45 d4       	cvtsi2sdl -0x2c(%rbp),%xmm0
  400ebb:	f2 0f 10 8d 48 fe ff 	movsd  -0x1b8(%rbp),%xmm1
  400ec2:	ff 
  400ec3:	f2 0f 2a 55 d0       	cvtsi2sdl -0x30(%rbp),%xmm2
  400ec8:	f2 0f 59 ca          	mulsd  %xmm2,%xmm1
  400ecc:	f2 0f 5c c1          	subsd  %xmm1,%xmm0
  400ed0:	f2 0f 2c d0          	cvttsd2si %xmm0,%edx
  400ed4:	89 95 34 fe ff ff    	mov    %edx,-0x1cc(%rbp)
  400eda:	f2 0f 10 85 48 fe ff 	movsd  -0x1b8(%rbp),%xmm0
  400ee1:	ff 
  400ee2:	8b b5 34 fe ff ff    	mov    -0x1cc(%rbp),%esi
  400ee8:	89 85 10 fd ff ff    	mov    %eax,-0x2f0(%rbp)
  400eee:	b0 01                	mov    $0x1,%al
  400ef0:	e8 7b f6 ff ff       	callq  400570 <printf@plt>
  400ef5:	f2 0f 2a 45 d0       	cvtsi2sdl -0x30(%rbp),%xmm0
  400efa:	f2 0f 58 85 40 fe ff 	addsd  -0x1c0(%rbp),%xmm0
  400f01:	ff 
  400f02:	f2 0f 2c d0          	cvttsd2si %xmm0,%edx
  400f06:	89 95 38 fe ff ff    	mov    %edx,-0x1c8(%rbp)
  400f0c:	89 85 0c fd ff ff    	mov    %eax,-0x2f4(%rbp)
  400f12:	8b 85 38 fe ff ff    	mov    -0x1c8(%rbp),%eax
  400f18:	3b 45 c8             	cmp    -0x38(%rbp),%eax
  400f1b:	0f 84 a6 00 00 00    	je     400fc7 <legalmove+0x8e7>
  400f21:	48 8d 3c 25 89 26 40 	lea    0x402689,%rdi
  400f28:	00 
  400f29:	8b b5 38 fe ff ff    	mov    -0x1c8(%rbp),%esi
  400f2f:	f2 0f 2c 85 48 fe ff 	cvttsd2si -0x1b8(%rbp),%eax
  400f36:	ff 
  400f37:	0f af 85 38 fe ff ff 	imul   -0x1c8(%rbp),%eax
  400f3e:	03 85 34 fe ff ff    	add    -0x1cc(%rbp),%eax
  400f44:	89 c2                	mov    %eax,%edx
  400f46:	b0 00                	mov    $0x0,%al
  400f48:	e8 23 f6 ff ff       	callq  400570 <printf@plt>
  400f4d:	48 8d bd 60 ff ff ff 	lea    -0xa0(%rbp),%rdi
  400f54:	48 63 8d 38 fe ff ff 	movslq -0x1c8(%rbp),%rcx
  400f5b:	f2 0f 2c 95 48 fe ff 	cvttsd2si -0x1b8(%rbp),%edx
  400f62:	ff 
  400f63:	0f af 95 38 fe ff ff 	imul   -0x1c8(%rbp),%edx
  400f6a:	03 95 34 fe ff ff    	add    -0x1cc(%rbp),%edx
  400f70:	4c 63 c2             	movslq %edx,%r8
  400f73:	4d 69 c0 09 00 00 00 	imul   $0x9,%r8,%r8
  400f7a:	4c 01 c7             	add    %r8,%rdi
  400f7d:	0f be 14 0f          	movsbl (%rdi,%rcx,1),%edx
  400f81:	81 fa 20 00 00 00    	cmp    $0x20,%edx
  400f87:	89 85 08 fd ff ff    	mov    %eax,-0x2f8(%rbp)
  400f8d:	0f 84 0c 00 00 00    	je     400f9f <legalmove+0x8bf>
  400f93:	c6 85 3f fe ff ff 01 	movb   $0x1,-0x1c1(%rbp)
  400f9a:	e9 28 00 00 00       	jmpq   400fc7 <legalmove+0x8e7>
  400f9f:	e9 00 00 00 00       	jmpq   400fa4 <legalmove+0x8c4>
  400fa4:	f2 0f 10 85 40 fe ff 	movsd  -0x1c0(%rbp),%xmm0
  400fab:	ff 
  400fac:	f2 0f 2a 8d 38 fe ff 	cvtsi2sdl -0x1c8(%rbp),%xmm1
  400fb3:	ff 
  400fb4:	f2 0f 58 c8          	addsd  %xmm0,%xmm1
  400fb8:	f2 0f 2c c1          	cvttsd2si %xmm1,%eax
  400fbc:	89 85 38 fe ff ff    	mov    %eax,-0x1c8(%rbp)
  400fc2:	e9 4b ff ff ff       	jmpq   400f12 <legalmove+0x832>
  400fc7:	8a 85 3f fe ff ff    	mov    -0x1c1(%rbp),%al
  400fcd:	24 01                	and    $0x1,%al
  400fcf:	0f b6 c8             	movzbl %al,%ecx
  400fd2:	81 f9 01 00 00 00    	cmp    $0x1,%ecx
  400fd8:	0f 85 1a 00 00 00    	jne    400ff8 <legalmove+0x918>
  400fde:	48 8d 3c 25 90 26 40 	lea    0x402690,%rdi
  400fe5:	00 
  400fe6:	b0 00                	mov    $0x0,%al
  400fe8:	e8 83 f5 ff ff       	callq  400570 <printf@plt>
  400fed:	89 85 04 fd ff ff    	mov    %eax,-0x2fc(%rbp)
  400ff3:	e9 0a 01 00 00       	jmpq   401102 <legalmove+0xa22>
  400ff8:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  400fff:	3d 42 00 00 00       	cmp    $0x42,%eax
  401004:	0f 84 12 00 00 00    	je     40101c <legalmove+0x93c>
  40100a:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  401011:	3d 62 00 00 00       	cmp    $0x62,%eax
  401016:	0f 85 0c 00 00 00    	jne    401028 <legalmove+0x948>
  40101c:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  401023:	e9 a3 06 00 00       	jmpq   4016cb <legalmove+0xfeb>
  401028:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  40102b:	05 01 00 00 00       	add    $0x1,%eax
  401030:	89 85 10 fe ff ff    	mov    %eax,-0x1f0(%rbp)
  401036:	8b 45 d0             	mov    -0x30(%rbp),%eax
  401039:	89 85 14 fe ff ff    	mov    %eax,-0x1ec(%rbp)
  40103f:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  401042:	2d 01 00 00 00       	sub    $0x1,%eax
  401047:	89 85 18 fe ff ff    	mov    %eax,-0x1e8(%rbp)
  40104d:	8b 45 d0             	mov    -0x30(%rbp),%eax
  401050:	89 85 1c fe ff ff    	mov    %eax,-0x1e4(%rbp)
  401056:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  401059:	89 85 20 fe ff ff    	mov    %eax,-0x1e0(%rbp)
  40105f:	8b 45 d0             	mov    -0x30(%rbp),%eax
  401062:	05 01 00 00 00       	add    $0x1,%eax
  401067:	89 85 24 fe ff ff    	mov    %eax,-0x1dc(%rbp)
  40106d:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  401070:	89 85 28 fe ff ff    	mov    %eax,-0x1d8(%rbp)
  401076:	8b 45 d0             	mov    -0x30(%rbp),%eax
  401079:	2d 01 00 00 00       	sub    $0x1,%eax
  40107e:	89 85 2c fe ff ff    	mov    %eax,-0x1d4(%rbp)
  401084:	c7 85 38 fe ff ff 00 	movl   $0x0,-0x1c8(%rbp)
  40108b:	00 00 00 
  40108e:	48 63 85 38 fe ff ff 	movslq -0x1c8(%rbp),%rax
  401095:	48 3d 04 00 00 00    	cmp    $0x4,%rax
  40109b:	0f 83 55 00 00 00    	jae    4010f6 <legalmove+0xa16>
  4010a1:	48 63 85 38 fe ff ff 	movslq -0x1c8(%rbp),%rax
  4010a8:	8b 8c c5 10 fe ff ff 	mov    -0x1f0(%rbp,%rax,8),%ecx
  4010af:	3b 4d cc             	cmp    -0x34(%rbp),%ecx
  4010b2:	0f 85 23 00 00 00    	jne    4010db <legalmove+0x9fb>
  4010b8:	48 63 85 38 fe ff ff 	movslq -0x1c8(%rbp),%rax
  4010bf:	8b 8c c5 14 fe ff ff 	mov    -0x1ec(%rbp,%rax,8),%ecx
  4010c6:	3b 4d c8             	cmp    -0x38(%rbp),%ecx
  4010c9:	0f 85 0c 00 00 00    	jne    4010db <legalmove+0x9fb>
  4010cf:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  4010d6:	e9 f0 05 00 00       	jmpq   4016cb <legalmove+0xfeb>
  4010db:	e9 00 00 00 00       	jmpq   4010e0 <legalmove+0xa00>
  4010e0:	8b 85 38 fe ff ff    	mov    -0x1c8(%rbp),%eax
  4010e6:	05 01 00 00 00       	add    $0x1,%eax
  4010eb:	89 85 38 fe ff ff    	mov    %eax,-0x1c8(%rbp)
  4010f1:	e9 98 ff ff ff       	jmpq   40108e <legalmove+0x9ae>
  4010f6:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  4010fd:	e9 c9 05 00 00       	jmpq   4016cb <legalmove+0xfeb>
  401102:	e9 9f 05 00 00       	jmpq   4016a6 <legalmove+0xfc6>
  401107:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  40110e:	3d 4c 00 00 00       	cmp    $0x4c,%eax
  401113:	0f 84 12 00 00 00    	je     40112b <legalmove+0xa4b>
  401119:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  401120:	3d 6c 00 00 00       	cmp    $0x6c,%eax
  401125:	0f 85 0a 01 00 00    	jne    401235 <legalmove+0xb55>
  40112b:	8b 45 bc             	mov    -0x44(%rbp),%eax
  40112e:	3b 45 c4             	cmp    -0x3c(%rbp),%eax
  401131:	0f 8e 0c 00 00 00    	jle    401143 <legalmove+0xa63>
  401137:	8b 45 d0             	mov    -0x30(%rbp),%eax
  40113a:	3b 45 c8             	cmp    -0x38(%rbp),%eax
  40113d:	0f 84 0c 00 00 00    	je     40114f <legalmove+0xa6f>
  401143:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  40114a:	e9 7c 05 00 00       	jmpq   4016cb <legalmove+0xfeb>
  40114f:	8b 45 cc             	mov    -0x34(%rbp),%eax
  401152:	3b 45 d4             	cmp    -0x2c(%rbp),%eax
  401155:	0f 8e 1c 00 00 00    	jle    401177 <legalmove+0xa97>
  40115b:	81 7d ec 02 00 00 00 	cmpl   $0x2,-0x14(%rbp)
  401162:	0f 85 0f 00 00 00    	jne    401177 <legalmove+0xa97>
  401168:	c7 85 0c fe ff ff 01 	movl   $0x1,-0x1f4(%rbp)
  40116f:	00 00 00 
  401172:	e9 39 00 00 00       	jmpq   4011b0 <legalmove+0xad0>
  401177:	8b 45 cc             	mov    -0x34(%rbp),%eax
  40117a:	3b 45 d4             	cmp    -0x2c(%rbp),%eax
  40117d:	0f 8d 1c 00 00 00    	jge    40119f <legalmove+0xabf>
  401183:	81 7d ec 01 00 00 00 	cmpl   $0x1,-0x14(%rbp)
  40118a:	0f 85 0f 00 00 00    	jne    40119f <legalmove+0xabf>
  401190:	c7 85 0c fe ff ff ff 	movl   $0xffffffff,-0x1f4(%rbp)
  401197:	ff ff ff 
  40119a:	e9 0c 00 00 00       	jmpq   4011ab <legalmove+0xacb>
  40119f:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  4011a6:	e9 20 05 00 00       	jmpq   4016cb <legalmove+0xfeb>
  4011ab:	e9 00 00 00 00       	jmpq   4011b0 <legalmove+0xad0>
  4011b0:	e9 00 00 00 00       	jmpq   4011b5 <legalmove+0xad5>
  4011b5:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  4011b8:	03 85 0c fe ff ff    	add    -0x1f4(%rbp),%eax
  4011be:	89 85 08 fe ff ff    	mov    %eax,-0x1f8(%rbp)
  4011c4:	8b 85 08 fe ff ff    	mov    -0x1f8(%rbp),%eax
  4011ca:	3b 45 cc             	cmp    -0x34(%rbp),%eax
  4011cd:	0f 84 56 00 00 00    	je     401229 <legalmove+0xb49>
  4011d3:	48 8d 85 60 ff ff ff 	lea    -0xa0(%rbp),%rax
  4011da:	48 63 8d 08 fe ff ff 	movslq -0x1f8(%rbp),%rcx
  4011e1:	48 63 55 d0          	movslq -0x30(%rbp),%rdx
  4011e5:	48 69 d2 09 00 00 00 	imul   $0x9,%rdx,%rdx
  4011ec:	48 01 d0             	add    %rdx,%rax
  4011ef:	0f be 34 08          	movsbl (%rax,%rcx,1),%esi
  4011f3:	81 fe 20 00 00 00    	cmp    $0x20,%esi
  4011f9:	0f 84 0c 00 00 00    	je     40120b <legalmove+0xb2b>
  4011ff:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  401206:	e9 c0 04 00 00       	jmpq   4016cb <legalmove+0xfeb>
  40120b:	e9 00 00 00 00       	jmpq   401210 <legalmove+0xb30>
  401210:	8b 85 0c fe ff ff    	mov    -0x1f4(%rbp),%eax
  401216:	8b 8d 08 fe ff ff    	mov    -0x1f8(%rbp),%ecx
  40121c:	01 c1                	add    %eax,%ecx
  40121e:	89 8d 08 fe ff ff    	mov    %ecx,-0x1f8(%rbp)
  401224:	e9 9b ff ff ff       	jmpq   4011c4 <legalmove+0xae4>
  401229:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  401230:	e9 96 04 00 00       	jmpq   4016cb <legalmove+0xfeb>
  401235:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  40123c:	3d 4b 00 00 00       	cmp    $0x4b,%eax
  401241:	0f 84 12 00 00 00    	je     401259 <legalmove+0xb79>
  401247:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  40124e:	3d 6b 00 00 00       	cmp    $0x6b,%eax
  401253:	0f 85 4a 01 00 00    	jne    4013a3 <legalmove+0xcc3>
  401259:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  40125c:	05 01 00 00 00       	add    $0x1,%eax
  401261:	89 85 c0 fd ff ff    	mov    %eax,-0x240(%rbp)
  401267:	8b 45 d0             	mov    -0x30(%rbp),%eax
  40126a:	05 01 00 00 00       	add    $0x1,%eax
  40126f:	89 85 c4 fd ff ff    	mov    %eax,-0x23c(%rbp)
  401275:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  401278:	05 01 00 00 00       	add    $0x1,%eax
  40127d:	89 85 c8 fd ff ff    	mov    %eax,-0x238(%rbp)
  401283:	8b 45 d0             	mov    -0x30(%rbp),%eax
  401286:	89 85 cc fd ff ff    	mov    %eax,-0x234(%rbp)
  40128c:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  40128f:	05 01 00 00 00       	add    $0x1,%eax
  401294:	89 85 d0 fd ff ff    	mov    %eax,-0x230(%rbp)
  40129a:	8b 45 d0             	mov    -0x30(%rbp),%eax
  40129d:	2d 01 00 00 00       	sub    $0x1,%eax
  4012a2:	89 85 d4 fd ff ff    	mov    %eax,-0x22c(%rbp)
  4012a8:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  4012ab:	89 85 d8 fd ff ff    	mov    %eax,-0x228(%rbp)
  4012b1:	8b 45 d0             	mov    -0x30(%rbp),%eax
  4012b4:	05 01 00 00 00       	add    $0x1,%eax
  4012b9:	89 85 dc fd ff ff    	mov    %eax,-0x224(%rbp)
  4012bf:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  4012c2:	89 85 e0 fd ff ff    	mov    %eax,-0x220(%rbp)
  4012c8:	8b 45 d0             	mov    -0x30(%rbp),%eax
  4012cb:	2d 01 00 00 00       	sub    $0x1,%eax
  4012d0:	89 85 e4 fd ff ff    	mov    %eax,-0x21c(%rbp)
  4012d6:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  4012d9:	2d 01 00 00 00       	sub    $0x1,%eax
  4012de:	89 85 e8 fd ff ff    	mov    %eax,-0x218(%rbp)
  4012e4:	8b 45 d0             	mov    -0x30(%rbp),%eax
  4012e7:	05 01 00 00 00       	add    $0x1,%eax
  4012ec:	89 85 ec fd ff ff    	mov    %eax,-0x214(%rbp)
  4012f2:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  4012f5:	2d 01 00 00 00       	sub    $0x1,%eax
  4012fa:	89 85 f0 fd ff ff    	mov    %eax,-0x210(%rbp)
  401300:	8b 45 d0             	mov    -0x30(%rbp),%eax
  401303:	89 85 f4 fd ff ff    	mov    %eax,-0x20c(%rbp)
  401309:	8b 45 d4             	mov    -0x2c(%rbp),%eax
  40130c:	2d 01 00 00 00       	sub    $0x1,%eax
  401311:	89 85 f8 fd ff ff    	mov    %eax,-0x208(%rbp)
  401317:	8b 45 d0             	mov    -0x30(%rbp),%eax
  40131a:	2d 01 00 00 00       	sub    $0x1,%eax
  40131f:	89 85 fc fd ff ff    	mov    %eax,-0x204(%rbp)
  401325:	c7 85 bc fd ff ff 00 	movl   $0x0,-0x244(%rbp)
  40132c:	00 00 00 
  40132f:	48 63 85 bc fd ff ff 	movslq -0x244(%rbp),%rax
  401336:	48 3d 08 00 00 00    	cmp    $0x8,%rax
  40133c:	0f 83 55 00 00 00    	jae    401397 <legalmove+0xcb7>
  401342:	48 63 85 bc fd ff ff 	movslq -0x244(%rbp),%rax
  401349:	8b 8c c5 c0 fd ff ff 	mov    -0x240(%rbp,%rax,8),%ecx
  401350:	3b 4d cc             	cmp    -0x34(%rbp),%ecx
  401353:	0f 85 23 00 00 00    	jne    40137c <legalmove+0xc9c>
  401359:	48 63 85 bc fd ff ff 	movslq -0x244(%rbp),%rax
  401360:	8b 8c c5 c4 fd ff ff 	mov    -0x23c(%rbp,%rax,8),%ecx
  401367:	3b 4d c8             	cmp    -0x38(%rbp),%ecx
  40136a:	0f 85 0c 00 00 00    	jne    40137c <legalmove+0xc9c>
  401370:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  401377:	e9 4f 03 00 00       	jmpq   4016cb <legalmove+0xfeb>
  40137c:	e9 00 00 00 00       	jmpq   401381 <legalmove+0xca1>
  401381:	8b 85 bc fd ff ff    	mov    -0x244(%rbp),%eax
  401387:	05 01 00 00 00       	add    $0x1,%eax
  40138c:	89 85 bc fd ff ff    	mov    %eax,-0x244(%rbp)
  401392:	e9 98 ff ff ff       	jmpq   40132f <legalmove+0xc4f>
  401397:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  40139e:	e9 28 03 00 00       	jmpq   4016cb <legalmove+0xfeb>
  4013a3:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  4013aa:	3d 47 00 00 00       	cmp    $0x47,%eax
  4013af:	0f 84 12 00 00 00    	je     4013c7 <legalmove+0xce7>
  4013b5:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  4013bc:	3d 67 00 00 00       	cmp    $0x67,%eax
  4013c1:	0f 85 05 01 00 00    	jne    4014cc <legalmove+0xdec>
  4013c7:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  4013ca:	05 01 00 00 00       	add    $0x1,%eax
  4013cf:	89 85 90 fd ff ff    	mov    %eax,-0x270(%rbp)
  4013d5:	8b 45 c0             	mov    -0x40(%rbp),%eax
  4013d8:	2d 01 00 00 00       	sub    $0x1,%eax
  4013dd:	89 85 94 fd ff ff    	mov    %eax,-0x26c(%rbp)
  4013e3:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  4013e6:	05 01 00 00 00       	add    $0x1,%eax
  4013eb:	89 85 98 fd ff ff    	mov    %eax,-0x268(%rbp)
  4013f1:	8b 45 c0             	mov    -0x40(%rbp),%eax
  4013f4:	89 85 9c fd ff ff    	mov    %eax,-0x264(%rbp)
  4013fa:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  4013fd:	05 01 00 00 00       	add    $0x1,%eax
  401402:	89 85 a0 fd ff ff    	mov    %eax,-0x260(%rbp)
  401408:	8b 45 c0             	mov    -0x40(%rbp),%eax
  40140b:	05 01 00 00 00       	add    $0x1,%eax
  401410:	89 85 a4 fd ff ff    	mov    %eax,-0x25c(%rbp)
  401416:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  401419:	2d 01 00 00 00       	sub    $0x1,%eax
  40141e:	89 85 a8 fd ff ff    	mov    %eax,-0x258(%rbp)
  401424:	8b 45 c0             	mov    -0x40(%rbp),%eax
  401427:	2d 01 00 00 00       	sub    $0x1,%eax
  40142c:	89 85 ac fd ff ff    	mov    %eax,-0x254(%rbp)
  401432:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  401435:	2d 01 00 00 00       	sub    $0x1,%eax
  40143a:	89 85 b0 fd ff ff    	mov    %eax,-0x250(%rbp)
  401440:	8b 45 c0             	mov    -0x40(%rbp),%eax
  401443:	05 01 00 00 00       	add    $0x1,%eax
  401448:	89 85 b4 fd ff ff    	mov    %eax,-0x24c(%rbp)
  40144e:	c7 85 b8 fd ff ff 00 	movl   $0x0,-0x248(%rbp)
  401455:	00 00 00 
  401458:	48 63 85 b8 fd ff ff 	movslq -0x248(%rbp),%rax
  40145f:	48 3d 05 00 00 00    	cmp    $0x5,%rax
  401465:	0f 83 55 00 00 00    	jae    4014c0 <legalmove+0xde0>
  40146b:	48 63 85 b8 fd ff ff 	movslq -0x248(%rbp),%rax
  401472:	8b 8c c5 90 fd ff ff 	mov    -0x270(%rbp,%rax,8),%ecx
  401479:	3b 4d bc             	cmp    -0x44(%rbp),%ecx
  40147c:	0f 85 23 00 00 00    	jne    4014a5 <legalmove+0xdc5>
  401482:	48 63 85 b8 fd ff ff 	movslq -0x248(%rbp),%rax
  401489:	8b 8c c5 94 fd ff ff 	mov    -0x26c(%rbp,%rax,8),%ecx
  401490:	3b 4d b8             	cmp    -0x48(%rbp),%ecx
  401493:	0f 85 0c 00 00 00    	jne    4014a5 <legalmove+0xdc5>
  401499:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  4014a0:	e9 26 02 00 00       	jmpq   4016cb <legalmove+0xfeb>
  4014a5:	e9 00 00 00 00       	jmpq   4014aa <legalmove+0xdca>
  4014aa:	8b 85 b8 fd ff ff    	mov    -0x248(%rbp),%eax
  4014b0:	05 01 00 00 00       	add    $0x1,%eax
  4014b5:	89 85 b8 fd ff ff    	mov    %eax,-0x248(%rbp)
  4014bb:	e9 98 ff ff ff       	jmpq   401458 <legalmove+0xd78>
  4014c0:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  4014c7:	e9 ff 01 00 00       	jmpq   4016cb <legalmove+0xfeb>
  4014cc:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  4014d3:	3d 55 00 00 00       	cmp    $0x55,%eax
  4014d8:	0f 84 a2 00 00 00    	je     401580 <legalmove+0xea0>
  4014de:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  4014e5:	3d 75 00 00 00       	cmp    $0x75,%eax
  4014ea:	0f 84 90 00 00 00    	je     401580 <legalmove+0xea0>
  4014f0:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  4014f7:	3d 48 00 00 00       	cmp    $0x48,%eax
  4014fc:	0f 84 7e 00 00 00    	je     401580 <legalmove+0xea0>
  401502:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  401509:	3d 68 00 00 00       	cmp    $0x68,%eax
  40150e:	0f 84 6c 00 00 00    	je     401580 <legalmove+0xea0>
  401514:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  40151b:	3d 51 00 00 00       	cmp    $0x51,%eax
  401520:	0f 84 5a 00 00 00    	je     401580 <legalmove+0xea0>
  401526:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  40152d:	3d 71 00 00 00       	cmp    $0x71,%eax
  401532:	0f 84 48 00 00 00    	je     401580 <legalmove+0xea0>
  401538:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  40153f:	3d 4d 00 00 00       	cmp    $0x4d,%eax
  401544:	0f 84 36 00 00 00    	je     401580 <legalmove+0xea0>
  40154a:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  401551:	3d 6d 00 00 00       	cmp    $0x6d,%eax
  401556:	0f 84 24 00 00 00    	je     401580 <legalmove+0xea0>
  40155c:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  401563:	3d 4f 00 00 00       	cmp    $0x4f,%eax
  401568:	0f 84 12 00 00 00    	je     401580 <legalmove+0xea0>
  40156e:	0f be 85 87 fe ff ff 	movsbl -0x179(%rbp),%eax
  401575:	3d 6f 00 00 00       	cmp    $0x6f,%eax
  40157a:	0f 85 12 01 00 00    	jne    401692 <legalmove+0xfb2>
  401580:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  401583:	05 01 00 00 00       	add    $0x1,%eax
  401588:	89 85 50 fd ff ff    	mov    %eax,-0x2b0(%rbp)
  40158e:	8b 45 c0             	mov    -0x40(%rbp),%eax
  401591:	2d 01 00 00 00       	sub    $0x1,%eax
  401596:	89 85 54 fd ff ff    	mov    %eax,-0x2ac(%rbp)
  40159c:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  40159f:	05 01 00 00 00       	add    $0x1,%eax
  4015a4:	89 85 58 fd ff ff    	mov    %eax,-0x2a8(%rbp)
  4015aa:	8b 45 c0             	mov    -0x40(%rbp),%eax
  4015ad:	89 85 5c fd ff ff    	mov    %eax,-0x2a4(%rbp)
  4015b3:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  4015b6:	05 01 00 00 00       	add    $0x1,%eax
  4015bb:	89 85 60 fd ff ff    	mov    %eax,-0x2a0(%rbp)
  4015c1:	8b 45 c0             	mov    -0x40(%rbp),%eax
  4015c4:	05 01 00 00 00       	add    $0x1,%eax
  4015c9:	89 85 64 fd ff ff    	mov    %eax,-0x29c(%rbp)
  4015cf:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  4015d2:	89 85 68 fd ff ff    	mov    %eax,-0x298(%rbp)
  4015d8:	8b 45 c0             	mov    -0x40(%rbp),%eax
  4015db:	2d 01 00 00 00       	sub    $0x1,%eax
  4015e0:	89 85 6c fd ff ff    	mov    %eax,-0x294(%rbp)
  4015e6:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  4015e9:	89 85 70 fd ff ff    	mov    %eax,-0x290(%rbp)
  4015ef:	8b 45 c0             	mov    -0x40(%rbp),%eax
  4015f2:	05 01 00 00 00       	add    $0x1,%eax
  4015f7:	89 85 74 fd ff ff    	mov    %eax,-0x28c(%rbp)
  4015fd:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  401600:	2d 01 00 00 00       	sub    $0x1,%eax
  401605:	89 85 78 fd ff ff    	mov    %eax,-0x288(%rbp)
  40160b:	8b 45 c0             	mov    -0x40(%rbp),%eax
  40160e:	89 85 7c fd ff ff    	mov    %eax,-0x284(%rbp)
  401614:	c7 85 8c fd ff ff 00 	movl   $0x0,-0x274(%rbp)
  40161b:	00 00 00 
  40161e:	48 63 85 8c fd ff ff 	movslq -0x274(%rbp),%rax
  401625:	48 3d 06 00 00 00    	cmp    $0x6,%rax
  40162b:	0f 83 55 00 00 00    	jae    401686 <legalmove+0xfa6>
  401631:	48 63 85 8c fd ff ff 	movslq -0x274(%rbp),%rax
  401638:	8b 8c c5 50 fd ff ff 	mov    -0x2b0(%rbp,%rax,8),%ecx
  40163f:	3b 4d bc             	cmp    -0x44(%rbp),%ecx
  401642:	0f 85 23 00 00 00    	jne    40166b <legalmove+0xf8b>
  401648:	48 63 85 8c fd ff ff 	movslq -0x274(%rbp),%rax
  40164f:	8b 8c c5 54 fd ff ff 	mov    -0x2ac(%rbp,%rax,8),%ecx
  401656:	3b 4d b8             	cmp    -0x48(%rbp),%ecx
  401659:	0f 85 0c 00 00 00    	jne    40166b <legalmove+0xf8b>
  40165f:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  401666:	e9 60 00 00 00       	jmpq   4016cb <legalmove+0xfeb>
  40166b:	e9 00 00 00 00       	jmpq   401670 <legalmove+0xf90>
  401670:	8b 85 8c fd ff ff    	mov    -0x274(%rbp),%eax
  401676:	05 01 00 00 00       	add    $0x1,%eax
  40167b:	89 85 8c fd ff ff    	mov    %eax,-0x274(%rbp)
  401681:	e9 98 ff ff ff       	jmpq   40161e <legalmove+0xf3e>
  401686:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  40168d:	e9 39 00 00 00       	jmpq   4016cb <legalmove+0xfeb>
  401692:	e9 00 00 00 00       	jmpq   401697 <legalmove+0xfb7>
  401697:	e9 00 00 00 00       	jmpq   40169c <legalmove+0xfbc>
  40169c:	e9 00 00 00 00       	jmpq   4016a1 <legalmove+0xfc1>
  4016a1:	e9 00 00 00 00       	jmpq   4016a6 <legalmove+0xfc6>
  4016a6:	e9 00 00 00 00       	jmpq   4016ab <legalmove+0xfcb>
  4016ab:	e9 00 00 00 00       	jmpq   4016b0 <legalmove+0xfd0>
  4016b0:	e9 00 00 00 00       	jmpq   4016b5 <legalmove+0xfd5>
  4016b5:	e9 00 00 00 00       	jmpq   4016ba <legalmove+0xfda>
  4016ba:	e9 00 00 00 00       	jmpq   4016bf <legalmove+0xfdf>
  4016bf:	e9 00 00 00 00       	jmpq   4016c4 <legalmove+0xfe4>
  4016c4:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  4016cb:	8b 45 fc             	mov    -0x4(%rbp),%eax
  4016ce:	48 81 c4 e0 03 00 00 	add    $0x3e0,%rsp
  4016d5:	5d                   	pop    %rbp
  4016d6:	c3                   	retq   
  4016d7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4016de:	00 00 

00000000004016e0 <legaldest>:
  4016e0:	55                   	push   %rbp
  4016e1:	48 89 e5             	mov    %rsp,%rbp
  4016e4:	48 83 ec 30          	sub    $0x30,%rsp
  4016e8:	b8 08 00 00 00       	mov    $0x8,%eax
  4016ed:	48 89 7d f0          	mov    %rdi,-0x10(%rbp)
  4016f1:	89 75 ec             	mov    %esi,-0x14(%rbp)
  4016f4:	89 55 e8             	mov    %edx,-0x18(%rbp)
  4016f7:	89 4d e4             	mov    %ecx,-0x1c(%rbp)
  4016fa:	2b 45 e4             	sub    -0x1c(%rbp),%eax
  4016fd:	89 45 e4             	mov    %eax,-0x1c(%rbp)
  401700:	48 63 7d e4          	movslq -0x1c(%rbp),%rdi
  401704:	4c 63 45 e8          	movslq -0x18(%rbp),%r8
  401708:	4c 8b 4d f0          	mov    -0x10(%rbp),%r9
  40170c:	4d 69 c0 09 00 00 00 	imul   $0x9,%r8,%r8
  401713:	4d 01 c1             	add    %r8,%r9
  401716:	45 8a 14 39          	mov    (%r9,%rdi,1),%r10b
  40171a:	44 88 55 e3          	mov    %r10b,-0x1d(%rbp)
  40171e:	8b 7d e8             	mov    -0x18(%rbp),%edi
  401721:	8b 75 e4             	mov    -0x1c(%rbp),%esi
  401724:	e8 d7 01 00 00       	callq  401900 <inrange>
  401729:	3d 00 00 00 00       	cmp    $0x0,%eax
  40172e:	0f 85 0c 00 00 00    	jne    401740 <legaldest+0x60>
  401734:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  40173b:	e9 ab 00 00 00       	jmpq   4017eb <legaldest+0x10b>
  401740:	81 7d ec 01 00 00 00 	cmpl   $0x1,-0x14(%rbp)
  401747:	0f 85 45 00 00 00    	jne    401792 <legaldest+0xb2>
  40174d:	0f be 45 e3          	movsbl -0x1d(%rbp),%eax
  401751:	48 63 c8             	movslq %eax,%rcx
  401754:	48 89 4d d8          	mov    %rcx,-0x28(%rbp)
  401758:	e8 83 ee ff ff       	callq  4005e0 <__ctype_b_loc@plt>
  40175d:	48 8b 00             	mov    (%rax),%rax
  401760:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
  401764:	0f b7 14 48          	movzwl (%rax,%rcx,2),%edx
  401768:	81 e2 00 01 00 00    	and    $0x100,%edx
  40176e:	81 fa 00 00 00 00    	cmp    $0x0,%edx
  401774:	0f 84 0c 00 00 00    	je     401786 <legaldest+0xa6>
  40177a:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  401781:	e9 65 00 00 00       	jmpq   4017eb <legaldest+0x10b>
  401786:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  40178d:	e9 59 00 00 00       	jmpq   4017eb <legaldest+0x10b>
  401792:	81 7d ec 02 00 00 00 	cmpl   $0x2,-0x14(%rbp)
  401799:	0f 85 45 00 00 00    	jne    4017e4 <legaldest+0x104>
  40179f:	0f be 45 e3          	movsbl -0x1d(%rbp),%eax
  4017a3:	48 63 c8             	movslq %eax,%rcx
  4017a6:	48 89 4d d0          	mov    %rcx,-0x30(%rbp)
  4017aa:	e8 31 ee ff ff       	callq  4005e0 <__ctype_b_loc@plt>
  4017af:	48 8b 00             	mov    (%rax),%rax
  4017b2:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
  4017b6:	0f b7 14 48          	movzwl (%rax,%rcx,2),%edx
  4017ba:	81 e2 00 02 00 00    	and    $0x200,%edx
  4017c0:	81 fa 00 00 00 00    	cmp    $0x0,%edx
  4017c6:	0f 84 0c 00 00 00    	je     4017d8 <legaldest+0xf8>
  4017cc:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  4017d3:	e9 13 00 00 00       	jmpq   4017eb <legaldest+0x10b>
  4017d8:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  4017df:	e9 07 00 00 00       	jmpq   4017eb <legaldest+0x10b>
  4017e4:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  4017eb:	8b 45 fc             	mov    -0x4(%rbp),%eax
  4017ee:	48 83 c4 30          	add    $0x30,%rsp
  4017f2:	5d                   	pop    %rbp
  4017f3:	c3                   	retq   
  4017f4:	66 66 66 2e 0f 1f 84 	data32 data32 nopw %cs:0x0(%rax,%rax,1)
  4017fb:	00 00 00 00 00 

0000000000401800 <legalsrc>:
  401800:	55                   	push   %rbp
  401801:	48 89 e5             	mov    %rsp,%rbp
  401804:	48 83 ec 30          	sub    $0x30,%rsp
  401808:	b8 08 00 00 00       	mov    $0x8,%eax
  40180d:	48 89 7d f0          	mov    %rdi,-0x10(%rbp)
  401811:	89 75 ec             	mov    %esi,-0x14(%rbp)
  401814:	89 55 e8             	mov    %edx,-0x18(%rbp)
  401817:	89 4d e4             	mov    %ecx,-0x1c(%rbp)
  40181a:	2b 45 e4             	sub    -0x1c(%rbp),%eax
  40181d:	89 45 e4             	mov    %eax,-0x1c(%rbp)
  401820:	48 63 7d e4          	movslq -0x1c(%rbp),%rdi
  401824:	4c 63 45 e8          	movslq -0x18(%rbp),%r8
  401828:	4c 8b 4d f0          	mov    -0x10(%rbp),%r9
  40182c:	4d 69 c0 09 00 00 00 	imul   $0x9,%r8,%r8
  401833:	4d 01 c1             	add    %r8,%r9
  401836:	45 8a 14 39          	mov    (%r9,%rdi,1),%r10b
  40183a:	44 88 55 e3          	mov    %r10b,-0x1d(%rbp)
  40183e:	8b 7d e8             	mov    -0x18(%rbp),%edi
  401841:	8b 75 e4             	mov    -0x1c(%rbp),%esi
  401844:	e8 b7 00 00 00       	callq  401900 <inrange>
  401849:	3d 00 00 00 00       	cmp    $0x0,%eax
  40184e:	0f 85 0c 00 00 00    	jne    401860 <legalsrc+0x60>
  401854:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  40185b:	e9 92 00 00 00       	jmpq   4018f2 <legalsrc+0xf2>
  401860:	81 7d ec 01 00 00 00 	cmpl   $0x1,-0x14(%rbp)
  401867:	0f 85 45 00 00 00    	jne    4018b2 <legalsrc+0xb2>
  40186d:	0f be 45 e3          	movsbl -0x1d(%rbp),%eax
  401871:	48 63 c8             	movslq %eax,%rcx
  401874:	48 89 4d d8          	mov    %rcx,-0x28(%rbp)
  401878:	e8 63 ed ff ff       	callq  4005e0 <__ctype_b_loc@plt>
  40187d:	48 8b 00             	mov    (%rax),%rax
  401880:	48 8b 4d d8          	mov    -0x28(%rbp),%rcx
  401884:	0f b7 14 48          	movzwl (%rax,%rcx,2),%edx
  401888:	81 e2 00 01 00 00    	and    $0x100,%edx
  40188e:	81 fa 00 00 00 00    	cmp    $0x0,%edx
  401894:	0f 84 0c 00 00 00    	je     4018a6 <legalsrc+0xa6>
  40189a:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  4018a1:	e9 4c 00 00 00       	jmpq   4018f2 <legalsrc+0xf2>
  4018a6:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  4018ad:	e9 40 00 00 00       	jmpq   4018f2 <legalsrc+0xf2>
  4018b2:	0f be 45 e3          	movsbl -0x1d(%rbp),%eax
  4018b6:	48 63 c8             	movslq %eax,%rcx
  4018b9:	48 89 4d d0          	mov    %rcx,-0x30(%rbp)
  4018bd:	e8 1e ed ff ff       	callq  4005e0 <__ctype_b_loc@plt>
  4018c2:	48 8b 00             	mov    (%rax),%rax
  4018c5:	48 8b 4d d0          	mov    -0x30(%rbp),%rcx
  4018c9:	0f b7 14 48          	movzwl (%rax,%rcx,2),%edx
  4018cd:	81 e2 00 02 00 00    	and    $0x200,%edx
  4018d3:	81 fa 00 00 00 00    	cmp    $0x0,%edx
  4018d9:	0f 84 0c 00 00 00    	je     4018eb <legalsrc+0xeb>
  4018df:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  4018e6:	e9 07 00 00 00       	jmpq   4018f2 <legalsrc+0xf2>
  4018eb:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  4018f2:	8b 45 fc             	mov    -0x4(%rbp),%eax
  4018f5:	48 83 c4 30          	add    $0x30,%rsp
  4018f9:	5d                   	pop    %rbp
  4018fa:	c3                   	retq   
  4018fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000401900 <inrange>:
  401900:	55                   	push   %rbp
  401901:	48 89 e5             	mov    %rsp,%rbp
  401904:	89 7d f8             	mov    %edi,-0x8(%rbp)
  401907:	89 75 f4             	mov    %esi,-0xc(%rbp)
  40190a:	81 7d f8 08 00 00 00 	cmpl   $0x8,-0x8(%rbp)
  401911:	0f 8f 27 00 00 00    	jg     40193e <inrange+0x3e>
  401917:	81 7d f8 00 00 00 00 	cmpl   $0x0,-0x8(%rbp)
  40191e:	0f 8c 1a 00 00 00    	jl     40193e <inrange+0x3e>
  401924:	81 7d f4 08 00 00 00 	cmpl   $0x8,-0xc(%rbp)
  40192b:	0f 8f 0d 00 00 00    	jg     40193e <inrange+0x3e>
  401931:	81 7d f4 00 00 00 00 	cmpl   $0x0,-0xc(%rbp)
  401938:	0f 8d 0c 00 00 00    	jge    40194a <inrange+0x4a>
  40193e:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  401945:	e9 07 00 00 00       	jmpq   401951 <inrange+0x51>
  40194a:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  401951:	8b 45 fc             	mov    -0x4(%rbp),%eax
  401954:	5d                   	pop    %rbp
  401955:	c3                   	retq   
  401956:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40195d:	00 00 00 

0000000000401960 <legaldrop>:
  401960:	55                   	push   %rbp
  401961:	48 89 e5             	mov    %rsp,%rbp
  401964:	48 81 ec b0 00 00 00 	sub    $0xb0,%rsp
  40196b:	88 d0                	mov    %dl,%al
  40196d:	4c 8d 45 80          	lea    -0x80(%rbp),%r8
  401971:	48 ba 51 00 00 00 00 	movabs $0x51,%rdx
  401978:	00 00 00 
  40197b:	48 89 7d f0          	mov    %rdi,-0x10(%rbp)
  40197f:	89 75 ec             	mov    %esi,-0x14(%rbp)
  401982:	88 45 eb             	mov    %al,-0x15(%rbp)
  401985:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
  401989:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  40198d:	8b 31                	mov    (%rcx),%esi
  40198f:	89 75 dc             	mov    %esi,-0x24(%rbp)
  401992:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  401996:	8b 71 04             	mov    0x4(%rcx),%esi
  401999:	89 75 d8             	mov    %esi,-0x28(%rbp)
  40199c:	4c 89 c1             	mov    %r8,%rcx
  40199f:	48 8b 7d f0          	mov    -0x10(%rbp),%rdi
  4019a3:	48 89 bd 70 ff ff ff 	mov    %rdi,-0x90(%rbp)
  4019aa:	48 89 cf             	mov    %rcx,%rdi
  4019ad:	48 8b b5 70 ff ff ff 	mov    -0x90(%rbp),%rsi
  4019b4:	4c 89 85 68 ff ff ff 	mov    %r8,-0x98(%rbp)
  4019bb:	e8 f0 eb ff ff       	callq  4005b0 <memcpy@plt>
  4019c0:	48 63 4d d8          	movslq -0x28(%rbp),%rcx
  4019c4:	48 63 55 dc          	movslq -0x24(%rbp),%rdx
  4019c8:	48 69 d2 09 00 00 00 	imul   $0x9,%rdx,%rdx
  4019cf:	48 8b b5 68 ff ff ff 	mov    -0x98(%rbp),%rsi
  4019d6:	48 01 d6             	add    %rdx,%rsi
  4019d9:	8a 04 0e             	mov    (%rsi,%rcx,1),%al
  4019dc:	88 85 7f ff ff ff    	mov    %al,-0x81(%rbp)
  4019e2:	44 0f be 8d 7f ff ff 	movsbl -0x81(%rbp),%r9d
  4019e9:	ff 
  4019ea:	41 81 f9 20 00 00 00 	cmp    $0x20,%r9d
  4019f1:	0f 84 0c 00 00 00    	je     401a03 <legaldrop+0xa3>
  4019f7:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  4019fe:	e9 94 01 00 00       	jmpq   401b97 <legaldrop+0x237>
  401a03:	48 8b 7d f0          	mov    -0x10(%rbp),%rdi
  401a07:	8b 75 ec             	mov    -0x14(%rbp),%esi
  401a0a:	8b 55 dc             	mov    -0x24(%rbp),%edx
  401a0d:	8b 4d d8             	mov    -0x28(%rbp),%ecx
  401a10:	e8 cb fc ff ff       	callq  4016e0 <legaldest>
  401a15:	3d 00 00 00 00       	cmp    $0x0,%eax
  401a1a:	0f 85 0c 00 00 00    	jne    401a2c <legaldrop+0xcc>
  401a20:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  401a27:	e9 6b 01 00 00       	jmpq   401b97 <legaldrop+0x237>
  401a2c:	81 7d ec 01 00 00 00 	cmpl   $0x1,-0x14(%rbp)
  401a33:	0f 85 3f 00 00 00    	jne    401a78 <legaldrop+0x118>
  401a39:	0f be 45 eb          	movsbl -0x15(%rbp),%eax
  401a3d:	48 63 c8             	movslq %eax,%rcx
  401a40:	48 89 8d 60 ff ff ff 	mov    %rcx,-0xa0(%rbp)
  401a47:	e8 94 eb ff ff       	callq  4005e0 <__ctype_b_loc@plt>
  401a4c:	48 8b 00             	mov    (%rax),%rax
  401a4f:	48 8b 8d 60 ff ff ff 	mov    -0xa0(%rbp),%rcx
  401a56:	0f b7 14 48          	movzwl (%rax,%rcx,2),%edx
  401a5a:	81 e2 00 01 00 00    	and    $0x100,%edx
  401a60:	81 fa 00 00 00 00    	cmp    $0x0,%edx
  401a66:	0f 84 0c 00 00 00    	je     401a78 <legaldrop+0x118>
  401a6c:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  401a73:	e9 1f 01 00 00       	jmpq   401b97 <legaldrop+0x237>
  401a78:	0f be 45 eb          	movsbl -0x15(%rbp),%eax
  401a7c:	48 63 c8             	movslq %eax,%rcx
  401a7f:	48 89 8d 58 ff ff ff 	mov    %rcx,-0xa8(%rbp)
  401a86:	e8 55 eb ff ff       	callq  4005e0 <__ctype_b_loc@plt>
  401a8b:	48 8b 00             	mov    (%rax),%rax
  401a8e:	48 8b 8d 58 ff ff ff 	mov    -0xa8(%rbp),%rcx
  401a95:	0f b7 14 48          	movzwl (%rax,%rcx,2),%edx
  401a99:	81 e2 00 02 00 00    	and    $0x200,%edx
  401a9f:	81 fa 00 00 00 00    	cmp    $0x0,%edx
  401aa5:	0f 84 0c 00 00 00    	je     401ab7 <legaldrop+0x157>
  401aab:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  401ab2:	e9 e0 00 00 00       	jmpq   401b97 <legaldrop+0x237>
  401ab7:	81 7d ec 01 00 00 00 	cmpl   $0x1,-0x14(%rbp)
  401abe:	0f 85 6c 00 00 00    	jne    401b30 <legaldrop+0x1d0>
  401ac4:	c7 85 78 ff ff ff 00 	movl   $0x0,-0x88(%rbp)
  401acb:	00 00 00 
  401ace:	81 bd 78 ff ff ff 26 	cmpl   $0x26,-0x88(%rbp)
  401ad5:	00 00 00 
  401ad8:	0f 8d 46 00 00 00    	jge    401b24 <legaldrop+0x1c4>
  401ade:	48 63 85 78 ff ff ff 	movslq -0x88(%rbp),%rax
  401ae5:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  401ae9:	0f be 94 01 84 00 00 	movsbl 0x84(%rcx,%rax,1),%edx
  401af0:	00 
  401af1:	0f be 75 eb          	movsbl -0x15(%rbp),%esi
  401af5:	39 f2                	cmp    %esi,%edx
  401af7:	0f 85 0c 00 00 00    	jne    401b09 <legaldrop+0x1a9>
  401afd:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  401b04:	e9 8e 00 00 00       	jmpq   401b97 <legaldrop+0x237>
  401b09:	e9 00 00 00 00       	jmpq   401b0e <legaldrop+0x1ae>
  401b0e:	8b 85 78 ff ff ff    	mov    -0x88(%rbp),%eax
  401b14:	05 01 00 00 00       	add    $0x1,%eax
  401b19:	89 85 78 ff ff ff    	mov    %eax,-0x88(%rbp)
  401b1f:	e9 aa ff ff ff       	jmpq   401ace <legaldrop+0x16e>
  401b24:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  401b2b:	e9 67 00 00 00       	jmpq   401b97 <legaldrop+0x237>
  401b30:	c7 85 78 ff ff ff 00 	movl   $0x0,-0x88(%rbp)
  401b37:	00 00 00 
  401b3a:	81 bd 78 ff ff ff 26 	cmpl   $0x26,-0x88(%rbp)
  401b41:	00 00 00 
  401b44:	0f 8d 46 00 00 00    	jge    401b90 <legaldrop+0x230>
  401b4a:	48 63 85 78 ff ff ff 	movslq -0x88(%rbp),%rax
  401b51:	48 8b 4d f0          	mov    -0x10(%rbp),%rcx
  401b55:	0f be 94 01 aa 00 00 	movsbl 0xaa(%rcx,%rax,1),%edx
  401b5c:	00 
  401b5d:	0f be 75 eb          	movsbl -0x15(%rbp),%esi
  401b61:	39 f2                	cmp    %esi,%edx
  401b63:	0f 85 0c 00 00 00    	jne    401b75 <legaldrop+0x215>
  401b69:	c7 45 fc 01 00 00 00 	movl   $0x1,-0x4(%rbp)
  401b70:	e9 22 00 00 00       	jmpq   401b97 <legaldrop+0x237>
  401b75:	e9 00 00 00 00       	jmpq   401b7a <legaldrop+0x21a>
  401b7a:	8b 85 78 ff ff ff    	mov    -0x88(%rbp),%eax
  401b80:	05 01 00 00 00       	add    $0x1,%eax
  401b85:	89 85 78 ff ff ff    	mov    %eax,-0x88(%rbp)
  401b8b:	e9 aa ff ff ff       	jmpq   401b3a <legaldrop+0x1da>
  401b90:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  401b97:	8b 45 fc             	mov    -0x4(%rbp),%eax
  401b9a:	48 81 c4 b0 00 00 00 	add    $0xb0,%rsp
  401ba1:	5d                   	pop    %rbp
  401ba2:	c3                   	retq   
  401ba3:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  401baa:	00 00 00 
  401bad:	0f 1f 00             	nopl   (%rax)

0000000000401bb0 <mkmove>:
  401bb0:	55                   	push   %rbp
  401bb1:	48 89 e5             	mov    %rsp,%rbp
  401bb4:	48 83 ec 40          	sub    $0x40,%rsp
  401bb8:	b8 08 00 00 00       	mov    $0x8,%eax
  401bbd:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  401bc1:	89 75 f4             	mov    %esi,-0xc(%rbp)
  401bc4:	48 89 55 e8          	mov    %rdx,-0x18(%rbp)
  401bc8:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
  401bcc:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  401bd0:	8b 31                	mov    (%rcx),%esi
  401bd2:	89 75 dc             	mov    %esi,-0x24(%rbp)
  401bd5:	48 8b 4d e0          	mov    -0x20(%rbp),%rcx
  401bd9:	89 c6                	mov    %eax,%esi
  401bdb:	2b 71 04             	sub    0x4(%rcx),%esi
  401bde:	89 75 d8             	mov    %esi,-0x28(%rbp)
  401be1:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
  401be5:	8b 31                	mov    (%rcx),%esi
  401be7:	89 75 d4             	mov    %esi,-0x2c(%rbp)
  401bea:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
  401bee:	2b 41 04             	sub    0x4(%rcx),%eax
  401bf1:	89 45 d0             	mov    %eax,-0x30(%rbp)
  401bf4:	48 63 4d d0          	movslq -0x30(%rbp),%rcx
  401bf8:	48 63 55 d4          	movslq -0x2c(%rbp),%rdx
  401bfc:	48 8b 7d f8          	mov    -0x8(%rbp),%rdi
  401c00:	48 69 d2 09 00 00 00 	imul   $0x9,%rdx,%rdx
  401c07:	48 01 d7             	add    %rdx,%rdi
  401c0a:	0f be 04 0f          	movsbl (%rdi,%rcx,1),%eax
  401c0e:	89 45 cc             	mov    %eax,-0x34(%rbp)
  401c11:	48 63 4d d8          	movslq -0x28(%rbp),%rcx
  401c15:	48 63 55 dc          	movslq -0x24(%rbp),%rdx
  401c19:	48 8b 7d f8          	mov    -0x8(%rbp),%rdi
  401c1d:	48 69 d2 09 00 00 00 	imul   $0x9,%rdx,%rdx
  401c24:	48 01 d7             	add    %rdx,%rdi
  401c27:	0f be 04 0f          	movsbl (%rdi,%rcx,1),%eax
  401c2b:	89 45 c8             	mov    %eax,-0x38(%rbp)
  401c2e:	48 63 4d d0          	movslq -0x30(%rbp),%rcx
  401c32:	48 63 55 d4          	movslq -0x2c(%rbp),%rdx
  401c36:	48 8b 7d f8          	mov    -0x8(%rbp),%rdi
  401c3a:	48 69 d2 09 00 00 00 	imul   $0x9,%rdx,%rdx
  401c41:	48 01 d7             	add    %rdx,%rdi
  401c44:	c6 04 0f 20          	movb   $0x20,(%rdi,%rcx,1)
  401c48:	8b 45 cc             	mov    -0x34(%rbp),%eax
  401c4b:	41 88 c0             	mov    %al,%r8b
  401c4e:	48 63 4d d8          	movslq -0x28(%rbp),%rcx
  401c52:	48 63 55 dc          	movslq -0x24(%rbp),%rdx
  401c56:	48 8b 7d f8          	mov    -0x8(%rbp),%rdi
  401c5a:	48 69 d2 09 00 00 00 	imul   $0x9,%rdx,%rdx
  401c61:	48 01 d7             	add    %rdx,%rdi
  401c64:	44 88 04 0f          	mov    %r8b,(%rdi,%rcx,1)
  401c68:	81 7d c8 20 00 00 00 	cmpl   $0x20,-0x38(%rbp)
  401c6f:	0f 84 d8 00 00 00    	je     401d4d <mkmove+0x19d>
  401c75:	81 7d f4 01 00 00 00 	cmpl   $0x1,-0xc(%rbp)
  401c7c:	0f 85 63 00 00 00    	jne    401ce5 <mkmove+0x135>
  401c82:	c7 45 c4 00 00 00 00 	movl   $0x0,-0x3c(%rbp)
  401c89:	81 7d c4 26 00 00 00 	cmpl   $0x26,-0x3c(%rbp)
  401c90:	0f 8d 4a 00 00 00    	jge    401ce0 <mkmove+0x130>
  401c96:	48 63 45 c4          	movslq -0x3c(%rbp),%rax
  401c9a:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  401c9e:	0f be 94 01 84 00 00 	movsbl 0x84(%rcx,%rax,1),%edx
  401ca5:	00 
  401ca6:	81 fa 00 00 00 00    	cmp    $0x0,%edx
  401cac:	0f 84 19 00 00 00    	je     401ccb <mkmove+0x11b>
  401cb2:	8b 45 c8             	mov    -0x38(%rbp),%eax
  401cb5:	05 20 00 00 00       	add    $0x20,%eax
  401cba:	88 c1                	mov    %al,%cl
  401cbc:	48 63 55 c4          	movslq -0x3c(%rbp),%rdx
  401cc0:	48 8b 75 f8          	mov    -0x8(%rbp),%rsi
  401cc4:	88 8c 16 84 00 00 00 	mov    %cl,0x84(%rsi,%rdx,1)
  401ccb:	e9 00 00 00 00       	jmpq   401cd0 <mkmove+0x120>
  401cd0:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  401cd3:	05 01 00 00 00       	add    $0x1,%eax
  401cd8:	89 45 c4             	mov    %eax,-0x3c(%rbp)
  401cdb:	e9 a9 ff ff ff       	jmpq   401c89 <mkmove+0xd9>
  401ce0:	e9 63 00 00 00       	jmpq   401d48 <mkmove+0x198>
  401ce5:	c7 45 c4 00 00 00 00 	movl   $0x0,-0x3c(%rbp)
  401cec:	81 7d c4 26 00 00 00 	cmpl   $0x26,-0x3c(%rbp)
  401cf3:	0f 8d 4a 00 00 00    	jge    401d43 <mkmove+0x193>
  401cf9:	48 63 45 c4          	movslq -0x3c(%rbp),%rax
  401cfd:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  401d01:	0f be 94 01 aa 00 00 	movsbl 0xaa(%rcx,%rax,1),%edx
  401d08:	00 
  401d09:	81 fa 00 00 00 00    	cmp    $0x0,%edx
  401d0f:	0f 84 19 00 00 00    	je     401d2e <mkmove+0x17e>
  401d15:	8b 45 cc             	mov    -0x34(%rbp),%eax
  401d18:	2d 20 00 00 00       	sub    $0x20,%eax
  401d1d:	88 c1                	mov    %al,%cl
  401d1f:	48 63 55 c4          	movslq -0x3c(%rbp),%rdx
  401d23:	48 8b 75 f8          	mov    -0x8(%rbp),%rsi
  401d27:	88 8c 16 aa 00 00 00 	mov    %cl,0xaa(%rsi,%rdx,1)
  401d2e:	e9 00 00 00 00       	jmpq   401d33 <mkmove+0x183>
  401d33:	8b 45 c4             	mov    -0x3c(%rbp),%eax
  401d36:	05 01 00 00 00       	add    $0x1,%eax
  401d3b:	89 45 c4             	mov    %eax,-0x3c(%rbp)
  401d3e:	e9 a9 ff ff ff       	jmpq   401cec <mkmove+0x13c>
  401d43:	e9 00 00 00 00       	jmpq   401d48 <mkmove+0x198>
  401d48:	e9 00 00 00 00       	jmpq   401d4d <mkmove+0x19d>
  401d4d:	48 8b 7d f8          	mov    -0x8(%rbp),%rdi
  401d51:	e8 3a 07 00 00       	callq  402490 <clockUpdate>
  401d56:	48 83 c4 40          	add    $0x40,%rsp
  401d5a:	5d                   	pop    %rbp
  401d5b:	c3                   	retq   
  401d5c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401d60 <mkdrop>:
  401d60:	55                   	push   %rbp
  401d61:	48 89 e5             	mov    %rsp,%rbp
  401d64:	48 83 ec 30          	sub    $0x30,%rsp
  401d68:	88 d0                	mov    %dl,%al
  401d6a:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  401d6e:	89 75 f4             	mov    %esi,-0xc(%rbp)
  401d71:	88 45 f3             	mov    %al,-0xd(%rbp)
  401d74:	48 89 4d e8          	mov    %rcx,-0x18(%rbp)
  401d78:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%rbp)
  401d7f:	81 7d f4 01 00 00 00 	cmpl   $0x1,-0xc(%rbp)
  401d86:	0f 85 46 00 00 00    	jne    401dd2 <mkdrop+0x72>
  401d8c:	e9 00 00 00 00       	jmpq   401d91 <mkdrop+0x31>
  401d91:	48 63 45 e4          	movslq -0x1c(%rbp),%rax
  401d95:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  401d99:	0f be 94 01 84 00 00 	movsbl 0x84(%rcx,%rax,1),%edx
  401da0:	00 
  401da1:	0f be 75 f3          	movsbl -0xd(%rbp),%esi
  401da5:	39 f2                	cmp    %esi,%edx
  401da7:	0f 84 10 00 00 00    	je     401dbd <mkdrop+0x5d>
  401dad:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  401db0:	05 01 00 00 00       	add    $0x1,%eax
  401db5:	89 45 e4             	mov    %eax,-0x1c(%rbp)
  401db8:	e9 d4 ff ff ff       	jmpq   401d91 <mkdrop+0x31>
  401dbd:	48 63 45 e4          	movslq -0x1c(%rbp),%rax
  401dc1:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  401dc5:	c6 84 01 84 00 00 00 	movb   $0x0,0x84(%rcx,%rax,1)
  401dcc:	00 
  401dcd:	e9 41 00 00 00       	jmpq   401e13 <mkdrop+0xb3>
  401dd2:	e9 00 00 00 00       	jmpq   401dd7 <mkdrop+0x77>
  401dd7:	48 63 45 e4          	movslq -0x1c(%rbp),%rax
  401ddb:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  401ddf:	0f be 94 01 aa 00 00 	movsbl 0xaa(%rcx,%rax,1),%edx
  401de6:	00 
  401de7:	0f be 75 f3          	movsbl -0xd(%rbp),%esi
  401deb:	39 f2                	cmp    %esi,%edx
  401ded:	0f 84 10 00 00 00    	je     401e03 <mkdrop+0xa3>
  401df3:	8b 45 e4             	mov    -0x1c(%rbp),%eax
  401df6:	05 01 00 00 00       	add    $0x1,%eax
  401dfb:	89 45 e4             	mov    %eax,-0x1c(%rbp)
  401dfe:	e9 d4 ff ff ff       	jmpq   401dd7 <mkdrop+0x77>
  401e03:	48 63 45 e4          	movslq -0x1c(%rbp),%rax
  401e07:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  401e0b:	c6 84 01 aa 00 00 00 	movb   $0x0,0xaa(%rcx,%rax,1)
  401e12:	00 
  401e13:	b8 08 00 00 00       	mov    $0x8,%eax
  401e18:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
  401e1c:	2b 01                	sub    (%rcx),%eax
  401e1e:	89 45 e0             	mov    %eax,-0x20(%rbp)
  401e21:	48 8b 4d e8          	mov    -0x18(%rbp),%rcx
  401e25:	8b 41 04             	mov    0x4(%rcx),%eax
  401e28:	89 45 dc             	mov    %eax,-0x24(%rbp)
  401e2b:	8a 55 f3             	mov    -0xd(%rbp),%dl
  401e2e:	48 63 4d dc          	movslq -0x24(%rbp),%rcx
  401e32:	48 63 75 e0          	movslq -0x20(%rbp),%rsi
  401e36:	48 8b 7d f8          	mov    -0x8(%rbp),%rdi
  401e3a:	48 69 f6 09 00 00 00 	imul   $0x9,%rsi,%rsi
  401e41:	48 01 f7             	add    %rsi,%rdi
  401e44:	88 14 0f             	mov    %dl,(%rdi,%rcx,1)
  401e47:	48 8b 7d f8          	mov    -0x8(%rbp),%rdi
  401e4b:	e8 40 06 00 00       	callq  402490 <clockUpdate>
  401e50:	48 83 c4 30          	add    $0x30,%rsp
  401e54:	5d                   	pop    %rbp
  401e55:	c3                   	retq   
  401e56:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  401e5d:	00 00 00 

0000000000401e60 <ctocoords>:
  401e60:	55                   	push   %rbp
  401e61:	48 89 e5             	mov    %rsp,%rbp
  401e64:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  401e68:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
  401e6c:	48 8b 75 f0          	mov    -0x10(%rbp),%rsi
  401e70:	8a 46 01             	mov    0x1(%rsi),%al
  401e73:	88 45 ef             	mov    %al,-0x11(%rbp)
  401e76:	48 8b 75 f0          	mov    -0x10(%rbp),%rsi
  401e7a:	8a 06                	mov    (%rsi),%al
  401e7c:	88 45 ee             	mov    %al,-0x12(%rbp)
  401e7f:	0f be 4d ef          	movsbl -0x11(%rbp),%ecx
  401e83:	81 e9 61 00 00 00    	sub    $0x61,%ecx
  401e89:	89 4d e8             	mov    %ecx,-0x18(%rbp)
  401e8c:	0f be 4d ee          	movsbl -0x12(%rbp),%ecx
  401e90:	81 e9 31 00 00 00    	sub    $0x31,%ecx
  401e96:	89 4d e4             	mov    %ecx,-0x1c(%rbp)
  401e99:	8b 4d e8             	mov    -0x18(%rbp),%ecx
  401e9c:	48 8b 75 f8          	mov    -0x8(%rbp),%rsi
  401ea0:	89 0e                	mov    %ecx,(%rsi)
  401ea2:	8b 4d e4             	mov    -0x1c(%rbp),%ecx
  401ea5:	48 8b 75 f8          	mov    -0x8(%rbp),%rsi
  401ea9:	89 4e 04             	mov    %ecx,0x4(%rsi)
  401eac:	5d                   	pop    %rbp
  401ead:	c3                   	retq   
  401eae:	66 90                	xchg   %ax,%ax

0000000000401eb0 <ischeck>:
  401eb0:	55                   	push   %rbp
  401eb1:	48 89 e5             	mov    %rsp,%rbp
  401eb4:	48 81 ec 90 00 00 00 	sub    $0x90,%rsp
  401ebb:	48 8d 45 10          	lea    0x10(%rbp),%rax
  401ebf:	b9 02 00 00 00       	mov    $0x2,%ecx
  401ec4:	48 ba 51 00 00 00 00 	movabs $0x51,%rdx
  401ecb:	00 00 00 
  401ece:	48 8d 75 a0          	lea    -0x60(%rbp),%rsi
  401ed2:	89 7d fc             	mov    %edi,-0x4(%rbp)
  401ed5:	49 89 c0             	mov    %rax,%r8
  401ed8:	48 89 f7             	mov    %rsi,%rdi
  401edb:	4c 89 c6             	mov    %r8,%rsi
  401ede:	89 4d 80             	mov    %ecx,-0x80(%rbp)
  401ee1:	48 89 85 78 ff ff ff 	mov    %rax,-0x88(%rbp)
  401ee8:	e8 c3 e6 ff ff       	callq  4005b0 <memcpy@plt>
  401eed:	8b 45 fc             	mov    -0x4(%rbp),%eax
  401ef0:	99                   	cltd   
  401ef1:	8b 4d 80             	mov    -0x80(%rbp),%ecx
  401ef4:	f7 f9                	idiv   %ecx
  401ef6:	81 c2 01 00 00 00    	add    $0x1,%edx
  401efc:	89 55 9c             	mov    %edx,-0x64(%rbp)
  401eff:	81 7d fc 01 00 00 00 	cmpl   $0x1,-0x4(%rbp)
  401f06:	0f 85 07 00 00 00    	jne    401f13 <ischeck+0x63>
  401f0c:	c7 45 90 6b 00 00 00 	movl   $0x6b,-0x70(%rbp)
  401f13:	81 7d fc 02 00 00 00 	cmpl   $0x2,-0x4(%rbp)
  401f1a:	0f 85 07 00 00 00    	jne    401f27 <ischeck+0x77>
  401f20:	c7 45 90 4b 00 00 00 	movl   $0x4b,-0x70(%rbp)
  401f27:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
  401f2e:	81 7d f8 09 00 00 00 	cmpl   $0x9,-0x8(%rbp)
  401f35:	0f 8d 77 00 00 00    	jge    401fb2 <ischeck+0x102>
  401f3b:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
  401f42:	81 7d f4 09 00 00 00 	cmpl   $0x9,-0xc(%rbp)
  401f49:	0f 8d 4e 00 00 00    	jge    401f9d <ischeck+0xed>
  401f4f:	48 8d 45 a0          	lea    -0x60(%rbp),%rax
  401f53:	48 63 4d f4          	movslq -0xc(%rbp),%rcx
  401f57:	48 63 55 f8          	movslq -0x8(%rbp),%rdx
  401f5b:	48 69 d2 09 00 00 00 	imul   $0x9,%rdx,%rdx
  401f62:	48 01 d0             	add    %rdx,%rax
  401f65:	0f be 34 08          	movsbl (%rax,%rcx,1),%esi
  401f69:	3b 75 90             	cmp    -0x70(%rbp),%esi
  401f6c:	0f 85 16 00 00 00    	jne    401f88 <ischeck+0xd8>
  401f72:	b8 08 00 00 00       	mov    $0x8,%eax
  401f77:	8b 4d f8             	mov    -0x8(%rbp),%ecx
  401f7a:	89 4d 94             	mov    %ecx,-0x6c(%rbp)
  401f7d:	2b 45 f4             	sub    -0xc(%rbp),%eax
  401f80:	89 45 98             	mov    %eax,-0x68(%rbp)
  401f83:	e9 15 00 00 00       	jmpq   401f9d <ischeck+0xed>
  401f88:	e9 00 00 00 00       	jmpq   401f8d <ischeck+0xdd>
  401f8d:	8b 45 f4             	mov    -0xc(%rbp),%eax
  401f90:	05 01 00 00 00       	add    $0x1,%eax
  401f95:	89 45 f4             	mov    %eax,-0xc(%rbp)
  401f98:	e9 a5 ff ff ff       	jmpq   401f42 <ischeck+0x92>
  401f9d:	e9 00 00 00 00       	jmpq   401fa2 <ischeck+0xf2>
  401fa2:	8b 45 f8             	mov    -0x8(%rbp),%eax
  401fa5:	05 01 00 00 00       	add    $0x1,%eax
  401faa:	89 45 f8             	mov    %eax,-0x8(%rbp)
  401fad:	e9 7c ff ff ff       	jmpq   401f2e <ischeck+0x7e>
  401fb2:	c6 45 87 00          	movb   $0x0,-0x79(%rbp)
  401fb6:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%rbp)
  401fbd:	81 7d f8 09 00 00 00 	cmpl   $0x9,-0x8(%rbp)
  401fc4:	0f 8d 7a 00 00 00    	jge    402044 <ischeck+0x194>
  401fca:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
  401fd1:	81 7d f4 09 00 00 00 	cmpl   $0x9,-0xc(%rbp)
  401fd8:	0f 8d 51 00 00 00    	jge    40202f <ischeck+0x17f>
  401fde:	48 8d 4d 94          	lea    -0x6c(%rbp),%rcx
  401fe2:	48 8d 55 88          	lea    -0x78(%rbp),%rdx
  401fe6:	b8 08 00 00 00       	mov    $0x8,%eax
  401feb:	8b 75 f8             	mov    -0x8(%rbp),%esi
  401fee:	89 75 88             	mov    %esi,-0x78(%rbp)
  401ff1:	2b 45 f4             	sub    -0xc(%rbp),%eax
  401ff4:	89 45 8c             	mov    %eax,-0x74(%rbp)
  401ff7:	8b 75 9c             	mov    -0x64(%rbp),%esi
  401ffa:	48 8b bd 78 ff ff ff 	mov    -0x88(%rbp),%rdi
  402001:	e8 da e6 ff ff       	callq  4006e0 <legalmove>
  402006:	3d 01 00 00 00       	cmp    $0x1,%eax
  40200b:	0f 85 09 00 00 00    	jne    40201a <ischeck+0x16a>
  402011:	c6 45 87 01          	movb   $0x1,-0x79(%rbp)
  402015:	e9 15 00 00 00       	jmpq   40202f <ischeck+0x17f>
  40201a:	e9 00 00 00 00       	jmpq   40201f <ischeck+0x16f>
  40201f:	8b 45 f4             	mov    -0xc(%rbp),%eax
  402022:	05 01 00 00 00       	add    $0x1,%eax
  402027:	89 45 f4             	mov    %eax,-0xc(%rbp)
  40202a:	e9 a2 ff ff ff       	jmpq   401fd1 <ischeck+0x121>
  40202f:	e9 00 00 00 00       	jmpq   402034 <ischeck+0x184>
  402034:	8b 45 f8             	mov    -0x8(%rbp),%eax
  402037:	05 01 00 00 00       	add    $0x1,%eax
  40203c:	89 45 f8             	mov    %eax,-0x8(%rbp)
  40203f:	e9 79 ff ff ff       	jmpq   401fbd <ischeck+0x10d>
  402044:	8a 45 87             	mov    -0x79(%rbp),%al
  402047:	24 01                	and    $0x1,%al
  402049:	0f b6 c0             	movzbl %al,%eax
  40204c:	48 81 c4 90 00 00 00 	add    $0x90,%rsp
  402053:	5d                   	pop    %rbp
  402054:	c3                   	retq   
  402055:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
  40205c:	00 00 00 00 

0000000000402060 <ismate>:
  402060:	55                   	push   %rbp
  402061:	48 89 e5             	mov    %rsp,%rbp
  402064:	48 81 ec 60 03 00 00 	sub    $0x360,%rsp
  40206b:	48 8d 45 10          	lea    0x10(%rbp),%rax
  40206f:	48 ba d8 00 00 00 00 	movabs $0xd8,%rdx
  402076:	00 00 00 
  402079:	48 8d 8d d8 fd ff ff 	lea    -0x228(%rbp),%rcx
  402080:	48 be 44 01 00 00 00 	movabs $0x144,%rsi
  402087:	00 00 00 
  40208a:	4c 8d 85 b0 fe ff ff 	lea    -0x150(%rbp),%r8
  402091:	89 7d f8             	mov    %edi,-0x8(%rbp)
  402094:	49 89 c1             	mov    %rax,%r9
  402097:	4c 89 c7             	mov    %r8,%rdi
  40209a:	48 89 b5 a8 fd ff ff 	mov    %rsi,-0x258(%rbp)
  4020a1:	4c 89 ce             	mov    %r9,%rsi
  4020a4:	4c 8b 85 a8 fd ff ff 	mov    -0x258(%rbp),%r8
  4020ab:	48 89 95 a0 fd ff ff 	mov    %rdx,-0x260(%rbp)
  4020b2:	4c 89 c2             	mov    %r8,%rdx
  4020b5:	48 89 8d 98 fd ff ff 	mov    %rcx,-0x268(%rbp)
  4020bc:	48 89 85 90 fd ff ff 	mov    %rax,-0x270(%rbp)
  4020c3:	e8 e8 e4 ff ff       	callq  4005b0 <memcpy@plt>
  4020c8:	48 8b 85 98 fd ff ff 	mov    -0x268(%rbp),%rax
  4020cf:	48 8b 8d 90 fd ff ff 	mov    -0x270(%rbp),%rcx
  4020d6:	48 89 c7             	mov    %rax,%rdi
  4020d9:	48 89 ce             	mov    %rcx,%rsi
  4020dc:	48 8b 95 a0 fd ff ff 	mov    -0x260(%rbp),%rdx
  4020e3:	e8 c8 e4 ff ff       	callq  4005b0 <memcpy@plt>
  4020e8:	8b 7d f8             	mov    -0x8(%rbp),%edi
  4020eb:	48 89 e0             	mov    %rsp,%rax
  4020ee:	41 ba 1b 00 00 00    	mov    $0x1b,%r10d
  4020f4:	44 89 d1             	mov    %r10d,%ecx
  4020f7:	89 bd 8c fd ff ff    	mov    %edi,-0x274(%rbp)
  4020fd:	48 89 c7             	mov    %rax,%rdi
  402100:	48 8b b5 90 fd ff ff 	mov    -0x270(%rbp),%rsi
  402107:	f3 48 a5             	rep movsq %ds:(%rsi),%es:(%rdi)
  40210a:	8b bd 8c fd ff ff    	mov    -0x274(%rbp),%edi
  402110:	e8 9b fd ff ff       	callq  401eb0 <ischeck>
  402115:	3d 00 00 00 00       	cmp    $0x0,%eax
  40211a:	0f 85 0c 00 00 00    	jne    40212c <ismate+0xcc>
  402120:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  402127:	e9 f3 01 00 00       	jmpq   40231f <ismate+0x2bf>
  40212c:	c6 85 b7 fd ff ff 01 	movb   $0x1,-0x249(%rbp)
  402133:	c7 85 d4 fd ff ff 00 	movl   $0x0,-0x22c(%rbp)
  40213a:	00 00 00 
  40213d:	81 bd d4 fd ff ff 09 	cmpl   $0x9,-0x22c(%rbp)
  402144:	00 00 00 
  402147:	0f 8d c4 01 00 00    	jge    402311 <ismate+0x2b1>
  40214d:	c7 85 d0 fd ff ff 00 	movl   $0x0,-0x230(%rbp)
  402154:	00 00 00 
  402157:	81 bd d0 fd ff ff 09 	cmpl   $0x9,-0x230(%rbp)
  40215e:	00 00 00 
  402161:	0f 8d 8f 01 00 00    	jge    4022f6 <ismate+0x296>
  402167:	c7 85 cc fd ff ff 00 	movl   $0x0,-0x234(%rbp)
  40216e:	00 00 00 
  402171:	81 bd cc fd ff ff 09 	cmpl   $0x9,-0x234(%rbp)
  402178:	00 00 00 
  40217b:	0f 8d 5a 01 00 00    	jge    4022db <ismate+0x27b>
  402181:	c7 85 c8 fd ff ff 00 	movl   $0x0,-0x238(%rbp)
  402188:	00 00 00 
  40218b:	81 bd c8 fd ff ff 09 	cmpl   $0x9,-0x238(%rbp)
  402192:	00 00 00 
  402195:	0f 8d 25 01 00 00    	jge    4022c0 <ismate+0x260>
  40219b:	48 8d bd d8 fd ff ff 	lea    -0x228(%rbp),%rdi
  4021a2:	48 8d 8d b8 fd ff ff 	lea    -0x248(%rbp),%rcx
  4021a9:	48 8d 95 c0 fd ff ff 	lea    -0x240(%rbp),%rdx
  4021b0:	b8 08 00 00 00       	mov    $0x8,%eax
  4021b5:	8b b5 d4 fd ff ff    	mov    -0x22c(%rbp),%esi
  4021bb:	89 b5 c0 fd ff ff    	mov    %esi,-0x240(%rbp)
  4021c1:	89 c6                	mov    %eax,%esi
  4021c3:	2b b5 d0 fd ff ff    	sub    -0x230(%rbp),%esi
  4021c9:	89 b5 c4 fd ff ff    	mov    %esi,-0x23c(%rbp)
  4021cf:	8b b5 cc fd ff ff    	mov    -0x234(%rbp),%esi
  4021d5:	89 b5 b8 fd ff ff    	mov    %esi,-0x248(%rbp)
  4021db:	2b 85 c8 fd ff ff    	sub    -0x238(%rbp),%eax
  4021e1:	89 85 bc fd ff ff    	mov    %eax,-0x244(%rbp)
  4021e7:	8b 75 f8             	mov    -0x8(%rbp),%esi
  4021ea:	e8 f1 e4 ff ff       	callq  4006e0 <legalmove>
  4021ef:	3d 01 00 00 00       	cmp    $0x1,%eax
  4021f4:	0f 85 a6 00 00 00    	jne    4022a0 <ismate+0x240>
  4021fa:	48 8d bd d8 fd ff ff 	lea    -0x228(%rbp),%rdi
  402201:	48 8d 8d b8 fd ff ff 	lea    -0x248(%rbp),%rcx
  402208:	48 8d 95 c0 fd ff ff 	lea    -0x240(%rbp),%rdx
  40220f:	8b 75 f8             	mov    -0x8(%rbp),%esi
  402212:	e8 99 f9 ff ff       	callq  401bb0 <mkmove>
  402217:	8b 7d f8             	mov    -0x8(%rbp),%edi
  40221a:	48 89 e1             	mov    %rsp,%rcx
  40221d:	be 1b 00 00 00       	mov    $0x1b,%esi
  402222:	89 f2                	mov    %esi,%edx
  402224:	48 8d b5 d8 fd ff ff 	lea    -0x228(%rbp),%rsi
  40222b:	48 89 8d 80 fd ff ff 	mov    %rcx,-0x280(%rbp)
  402232:	48 89 d1             	mov    %rdx,%rcx
  402235:	48 8b 95 80 fd ff ff 	mov    -0x280(%rbp),%rdx
  40223c:	89 bd 7c fd ff ff    	mov    %edi,-0x284(%rbp)
  402242:	48 89 d7             	mov    %rdx,%rdi
  402245:	f3 48 a5             	rep movsq %ds:(%rsi),%es:(%rdi)
  402248:	8b bd 7c fd ff ff    	mov    -0x284(%rbp),%edi
  40224e:	e8 5d fc ff ff       	callq  401eb0 <ischeck>
  402253:	3d 00 00 00 00       	cmp    $0x0,%eax
  402258:	0f 85 1a 00 00 00    	jne    402278 <ismate+0x218>
  40225e:	c6 85 b7 fd ff ff 00 	movb   $0x0,-0x249(%rbp)
  402265:	8a 85 b7 fd ff ff    	mov    -0x249(%rbp),%al
  40226b:	24 01                	and    $0x1,%al
  40226d:	0f b6 c8             	movzbl %al,%ecx
  402270:	89 4d fc             	mov    %ecx,-0x4(%rbp)
  402273:	e9 a7 00 00 00       	jmpq   40231f <ismate+0x2bf>
  402278:	48 ba d8 00 00 00 00 	movabs $0xd8,%rdx
  40227f:	00 00 00 
  402282:	48 8d 85 d8 fd ff ff 	lea    -0x228(%rbp),%rax
  402289:	48 8b 8d 90 fd ff ff 	mov    -0x270(%rbp),%rcx
  402290:	48 89 c7             	mov    %rax,%rdi
  402293:	48 89 ce             	mov    %rcx,%rsi
  402296:	e8 15 e3 ff ff       	callq  4005b0 <memcpy@plt>
  40229b:	e9 05 00 00 00       	jmpq   4022a5 <ismate+0x245>
  4022a0:	e9 05 00 00 00       	jmpq   4022aa <ismate+0x24a>
  4022a5:	e9 00 00 00 00       	jmpq   4022aa <ismate+0x24a>
  4022aa:	8b 85 c8 fd ff ff    	mov    -0x238(%rbp),%eax
  4022b0:	05 01 00 00 00       	add    $0x1,%eax
  4022b5:	89 85 c8 fd ff ff    	mov    %eax,-0x238(%rbp)
  4022bb:	e9 cb fe ff ff       	jmpq   40218b <ismate+0x12b>
  4022c0:	e9 00 00 00 00       	jmpq   4022c5 <ismate+0x265>
  4022c5:	8b 85 cc fd ff ff    	mov    -0x234(%rbp),%eax
  4022cb:	05 01 00 00 00       	add    $0x1,%eax
  4022d0:	89 85 cc fd ff ff    	mov    %eax,-0x234(%rbp)
  4022d6:	e9 96 fe ff ff       	jmpq   402171 <ismate+0x111>
  4022db:	e9 00 00 00 00       	jmpq   4022e0 <ismate+0x280>
  4022e0:	8b 85 d0 fd ff ff    	mov    -0x230(%rbp),%eax
  4022e6:	05 01 00 00 00       	add    $0x1,%eax
  4022eb:	89 85 d0 fd ff ff    	mov    %eax,-0x230(%rbp)
  4022f1:	e9 61 fe ff ff       	jmpq   402157 <ismate+0xf7>
  4022f6:	e9 00 00 00 00       	jmpq   4022fb <ismate+0x29b>
  4022fb:	8b 85 d4 fd ff ff    	mov    -0x22c(%rbp),%eax
  402301:	05 01 00 00 00       	add    $0x1,%eax
  402306:	89 85 d4 fd ff ff    	mov    %eax,-0x22c(%rbp)
  40230c:	e9 2c fe ff ff       	jmpq   40213d <ismate+0xdd>
  402311:	8a 85 b7 fd ff ff    	mov    -0x249(%rbp),%al
  402317:	24 01                	and    $0x1,%al
  402319:	0f b6 c8             	movzbl %al,%ecx
  40231c:	89 4d fc             	mov    %ecx,-0x4(%rbp)
  40231f:	8b 45 fc             	mov    -0x4(%rbp),%eax
  402322:	48 81 c4 60 03 00 00 	add    $0x360,%rsp
  402329:	5d                   	pop    %rbp
  40232a:	c3                   	retq   
  40232b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000402330 <main>:
  402330:	55                   	push   %rbp
  402331:	48 89 e5             	mov    %rsp,%rbp
  402334:	48 81 ec c0 01 00 00 	sub    $0x1c0,%rsp
  40233b:	48 8d bd 28 ff ff ff 	lea    -0xd8(%rbp),%rdi
  402342:	c7 85 24 ff ff ff 01 	movl   $0x1,-0xdc(%rbp)
  402349:	00 00 00 
  40234c:	e8 5f 00 00 00       	callq  4023b0 <init_game>
  402351:	8b bd 24 ff ff ff    	mov    -0xdc(%rbp),%edi
  402357:	48 89 e0             	mov    %rsp,%rax
  40235a:	b9 1b 00 00 00       	mov    $0x1b,%ecx
  40235f:	48 8d b5 28 ff ff ff 	lea    -0xd8(%rbp),%rsi
  402366:	89 bd 20 ff ff ff    	mov    %edi,-0xe0(%rbp)
  40236c:	48 89 c7             	mov    %rax,%rdi
  40236f:	f3 48 a5             	rep movsq %ds:(%rsi),%es:(%rdi)
  402372:	8b bd 20 ff ff ff    	mov    -0xe0(%rbp),%edi
  402378:	e8 33 fb ff ff       	callq  401eb0 <ischeck>
  40237d:	48 8d 3c 25 86 26 40 	lea    0x402686,%rdi
  402384:	00 
  402385:	89 c6                	mov    %eax,%esi
  402387:	b0 00                	mov    $0x0,%al
  402389:	e8 e2 e1 ff ff       	callq  400570 <printf@plt>
  40238e:	be 00 00 00 00       	mov    $0x0,%esi
  402393:	89 85 1c ff ff ff    	mov    %eax,-0xe4(%rbp)
  402399:	89 f0                	mov    %esi,%eax
  40239b:	48 81 c4 c0 01 00 00 	add    $0x1c0,%rsp
  4023a2:	5d                   	pop    %rbp
  4023a3:	c3                   	retq   
  4023a4:	66 66 66 2e 0f 1f 84 	data32 data32 nopw %cs:0x0(%rax,%rax,1)
  4023ab:	00 00 00 00 00 

00000000004023b0 <init_game>:
  4023b0:	55                   	push   %rbp
  4023b1:	48 89 e5             	mov    %rsp,%rbp
  4023b4:	48 83 ec 20          	sub    $0x20,%rsp
  4023b8:	48 b8 ee 02 00 00 00 	movabs $0x2ee,%rax
  4023bf:	00 00 00 
  4023c2:	48 8d 34 25 a0 26 40 	lea    0x4026a0,%rsi
  4023c9:	00 
  4023ca:	48 ba 51 00 00 00 00 	movabs $0x51,%rdx
  4023d1:	00 00 00 
  4023d4:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  4023d8:	48 8b 7d f8          	mov    -0x8(%rbp),%rdi
  4023dc:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  4023e0:	e8 cb e1 ff ff       	callq  4005b0 <memcpy@plt>
  4023e5:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  4023e9:	c7 80 80 00 00 00 01 	movl   $0x1,0x80(%rax)
  4023f0:	00 00 00 
  4023f3:	48 8b 7d e8          	mov    -0x18(%rbp),%rdi
  4023f7:	e8 d4 e1 ff ff       	callq  4005d0 <malloc@plt>
  4023fc:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
  402400:	48 89 42 58          	mov    %rax,0x58(%rdx)
  402404:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%rbp)
  40240b:	81 7d f4 26 00 00 00 	cmpl   $0x26,-0xc(%rbp)
  402412:	0f 8d 30 00 00 00    	jge    402448 <init_game+0x98>
  402418:	48 63 45 f4          	movslq -0xc(%rbp),%rax
  40241c:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  402420:	c6 84 01 84 00 00 00 	movb   $0x0,0x84(%rcx,%rax,1)
  402427:	00 
  402428:	48 63 45 f4          	movslq -0xc(%rbp),%rax
  40242c:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  402430:	c6 84 01 aa 00 00 00 	movb   $0x0,0xaa(%rcx,%rax,1)
  402437:	00 
  402438:	8b 45 f4             	mov    -0xc(%rbp),%eax
  40243b:	05 01 00 00 00       	add    $0x1,%eax
  402440:	89 45 f4             	mov    %eax,-0xc(%rbp)
  402443:	e9 c3 ff ff ff       	jmpq   40240b <init_game+0x5b>
  402448:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  40244c:	c7 40 68 3c 00 00 00 	movl   $0x3c,0x68(%rax)
  402453:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  402457:	c7 40 60 3c 00 00 00 	movl   $0x3c,0x60(%rax)
  40245e:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  402462:	c7 40 6c 00 00 00 00 	movl   $0x0,0x6c(%rax)
  402469:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  40246d:	c7 40 64 00 00 00 00 	movl   $0x0,0x64(%rax)
  402474:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
  402478:	c7 40 78 0f 00 00 00 	movl   $0xf,0x78(%rax)
  40247f:	48 83 c4 20          	add    $0x20,%rsp
  402483:	5d                   	pop    %rbp
  402484:	c3                   	retq   
  402485:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40248c:	00 00 00 
  40248f:	90                   	nop

0000000000402490 <clockUpdate>:
  402490:	55                   	push   %rbp
  402491:	48 89 e5             	mov    %rsp,%rbp
  402494:	48 83 ec 50          	sub    $0x50,%rsp
  402498:	48 b8 00 00 00 00 00 	movabs $0x0,%rax
  40249f:	00 00 00 
  4024a2:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
  4024a6:	48 8b 7d f8          	mov    -0x8(%rbp),%rdi
  4024aa:	48 8b 4f 60          	mov    0x60(%rdi),%rcx
  4024ae:	48 89 4d d8          	mov    %rcx,-0x28(%rbp)
  4024b2:	48 8b 4f 68          	mov    0x68(%rdi),%rcx
  4024b6:	48 89 4d e0          	mov    %rcx,-0x20(%rbp)
  4024ba:	48 8b 4f 70          	mov    0x70(%rdi),%rcx
  4024be:	48 89 4d e8          	mov    %rcx,-0x18(%rbp)
  4024c2:	48 8b 4f 78          	mov    0x78(%rdi),%rcx
  4024c6:	48 89 4d f0          	mov    %rcx,-0x10(%rbp)
  4024ca:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
  4024ce:	8b 91 80 00 00 00    	mov    0x80(%rcx),%edx
  4024d4:	81 ea 01 00 00 00    	sub    $0x1,%edx
  4024da:	89 55 d4             	mov    %edx,-0x2c(%rbp)
  4024dd:	48 89 c7             	mov    %rax,%rdi
  4024e0:	e8 db e0 ff ff       	callq  4005c0 <time@plt>
  4024e5:	48 89 45 c8          	mov    %rax,-0x38(%rbp)
  4024e9:	48 8b 7d c8          	mov    -0x38(%rbp),%rdi
  4024ed:	48 8b 75 e8          	mov    -0x18(%rbp),%rsi
  4024f1:	e8 8a e0 ff ff       	callq  400580 <difftime@plt>
  4024f6:	ba 3c 00 00 00       	mov    $0x3c,%edx
  4024fb:	f2 48 0f 2c c0       	cvttsd2si %xmm0,%rax
  402500:	48 89 45 c0          	mov    %rax,-0x40(%rbp)
  402504:	48 8b 45 c0          	mov    -0x40(%rbp),%rax
  402508:	41 89 c0             	mov    %eax,%r8d
  40250b:	44 89 c0             	mov    %r8d,%eax
  40250e:	89 55 bc             	mov    %edx,-0x44(%rbp)
  402511:	99                   	cltd   
  402512:	44 8b 45 bc          	mov    -0x44(%rbp),%r8d
  402516:	41 f7 f8             	idiv   %r8d
  402519:	48 63 4d d4          	movslq -0x2c(%rbp),%rcx
  40251d:	8b 44 cd dc          	mov    -0x24(%rbp,%rcx,8),%eax
  402521:	29 d0                	sub    %edx,%eax
  402523:	89 44 cd dc          	mov    %eax,-0x24(%rbp,%rcx,8)
  402527:	48 8b 4d c0          	mov    -0x40(%rbp),%rcx
  40252b:	89 c8                	mov    %ecx,%eax
  40252d:	99                   	cltd   
  40252e:	41 f7 f8             	idiv   %r8d
  402531:	48 63 4d d4          	movslq -0x2c(%rbp),%rcx
  402535:	8b 54 cd d8          	mov    -0x28(%rbp,%rcx,8),%edx
  402539:	29 c2                	sub    %eax,%edx
  40253b:	89 54 cd d8          	mov    %edx,-0x28(%rbp,%rcx,8)
  40253f:	48 63 4d d4          	movslq -0x2c(%rbp),%rcx
  402543:	81 7c cd dc 00 00 00 	cmpl   $0x0,-0x24(%rbp,%rcx,8)
  40254a:	00 
  40254b:	0f 8d 28 00 00 00    	jge    402579 <clockUpdate+0xe9>
  402551:	48 63 45 d4          	movslq -0x2c(%rbp),%rax
  402555:	8b 4c c5 d8          	mov    -0x28(%rbp,%rax,8),%ecx
  402559:	81 c1 ff ff ff ff    	add    $0xffffffff,%ecx
  40255f:	89 4c c5 d8          	mov    %ecx,-0x28(%rbp,%rax,8)
  402563:	48 63 45 d4          	movslq -0x2c(%rbp),%rax
  402567:	8b 4c c5 dc          	mov    -0x24(%rbp,%rax,8),%ecx
  40256b:	81 c1 3c 00 00 00    	add    $0x3c,%ecx
  402571:	48 63 45 d4          	movslq -0x2c(%rbp),%rax
  402575:	89 4c c5 dc          	mov    %ecx,-0x24(%rbp,%rax,8)
  402579:	48 8b 45 c8          	mov    -0x38(%rbp),%rax
  40257d:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
  402581:	48 83 c4 50          	add    $0x50,%rsp
  402585:	5d                   	pop    %rbp
  402586:	c3                   	retq   
  402587:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  40258e:	00 00 

0000000000402590 <__libc_csu_init>:
  402590:	41 57                	push   %r15
  402592:	41 89 ff             	mov    %edi,%r15d
  402595:	41 56                	push   %r14
  402597:	49 89 f6             	mov    %rsi,%r14
  40259a:	41 55                	push   %r13
  40259c:	49 89 d5             	mov    %rdx,%r13
  40259f:	41 54                	push   %r12
  4025a1:	4c 8d 25 68 08 20 00 	lea    0x200868(%rip),%r12        # 602e10 <__frame_dummy_init_array_entry>
  4025a8:	55                   	push   %rbp
  4025a9:	48 8d 2d 68 08 20 00 	lea    0x200868(%rip),%rbp        # 602e18 <__init_array_end>
  4025b0:	53                   	push   %rbx
  4025b1:	4c 29 e5             	sub    %r12,%rbp
  4025b4:	31 db                	xor    %ebx,%ebx
  4025b6:	48 c1 fd 03          	sar    $0x3,%rbp
  4025ba:	48 83 ec 08          	sub    $0x8,%rsp
  4025be:	e8 75 df ff ff       	callq  400538 <_init>
  4025c3:	48 85 ed             	test   %rbp,%rbp
  4025c6:	74 1e                	je     4025e6 <__libc_csu_init+0x56>
  4025c8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  4025cf:	00 
  4025d0:	4c 89 ea             	mov    %r13,%rdx
  4025d3:	4c 89 f6             	mov    %r14,%rsi
  4025d6:	44 89 ff             	mov    %r15d,%edi
  4025d9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  4025dd:	48 83 c3 01          	add    $0x1,%rbx
  4025e1:	48 39 eb             	cmp    %rbp,%rbx
  4025e4:	75 ea                	jne    4025d0 <__libc_csu_init+0x40>
  4025e6:	48 83 c4 08          	add    $0x8,%rsp
  4025ea:	5b                   	pop    %rbx
  4025eb:	5d                   	pop    %rbp
  4025ec:	41 5c                	pop    %r12
  4025ee:	41 5d                	pop    %r13
  4025f0:	41 5e                	pop    %r14
  4025f2:	41 5f                	pop    %r15
  4025f4:	c3                   	retq   
  4025f5:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
  4025fc:	00 00 00 00 

0000000000402600 <__libc_csu_fini>:
  402600:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000402604 <_fini>:
  402604:	48 83 ec 08          	sub    $0x8,%rsp
  402608:	48 83 c4 08          	add    $0x8,%rsp
  40260c:	c3                   	retq   

Disassembly of section .rodata:

0000000000402610 <_IO_stdin_used>:
  402610:	01 00                	add    %eax,(%rax)
  402612:	02 00                	add    (%rax),%al
  402614:	69 6c 6c 65 67 61 6c 	imul   $0x646c6167,0x65(%rsp,%rbp,2),%ebp
  40261b:	64 
  40261c:	65                   	gs
  40261d:	73 74                	jae    402693 <_IO_stdin_used+0x83>
  40261f:	00 69 6c             	add    %ch,0x6c(%rcx)
  402622:	6c                   	insb   (%dx),%es:(%rdi)
  402623:	65                   	gs
  402624:	67 61                	addr32 (bad) 
  402626:	6c                   	insb   (%dx),%es:(%rdi)
  402627:	73 72                	jae    40269b <_IO_stdin_used+0x8b>
  402629:	63 00                	movslq (%rax),%eax
  40262b:	73 61                	jae    40268e <_IO_stdin_used+0x7e>
  40262d:	6d                   	insl   (%dx),%es:(%rdi)
  40262e:	65                   	gs
  40262f:	73 72                	jae    4026a3 <init_game.init_board+0x3>
  402631:	63 2f                	movslq (%rdi),%ebp
  402633:	64                   	fs
  402634:	73 74                	jae    4026aa <init_game.init_board+0xa>
  402636:	00 6d 6f             	add    %ch,0x6f(%rbp)
  402639:	76 65                	jbe    4026a0 <init_game.init_board>
  40263b:	20 70 75             	and    %dh,0x75(%rax)
  40263e:	74 73                	je     4026b3 <init_game.init_board+0x13>
  402640:	20 70 6c             	and    %dh,0x6c(%rax)
  402643:	61                   	(bad)  
  402644:	79 65                	jns    4026ab <init_game.init_board+0xb>
  402646:	72 20                	jb     402668 <_IO_stdin_used+0x58>
  402648:	69 6e 20 63 68 65 63 	imul   $0x63656863,0x20(%rsi),%ebp
  40264f:	6b 00 62             	imul   $0x62,(%rax),%eax
  402652:	61                   	(bad)  
  402653:	64 20 70 61          	and    %dh,%fs:0x61(%rax)
  402657:	77 6e                	ja     4026c7 <init_game.init_board+0x27>
  402659:	00 65 6e             	add    %ah,0x6e(%rbp)
  40265c:	74 65                	je     4026c3 <init_game.init_board+0x23>
  40265e:	72 73                	jb     4026d3 <init_game.init_board+0x33>
  402660:	20 72 6f             	and    %dh,0x6f(%rdx)
  402663:	6f                   	outsl  %ds:(%rsi),(%dx)
  402664:	6b 0a 00             	imul   $0x0,(%rdx),%ecx
  402667:	62 61 64 20 62       	(bad)  
  40266c:	69 73 68 6f 70 31 00 	imul   $0x31706f,0x68(%rbx),%esi
  402673:	28 28                	sub    %ch,(%rax)
  402675:	25 69 20 2b 20       	and    $0x202b2069,%eax
  40267a:	25 69 29 29 00       	and    $0x292969,%eax
  40267f:	25 66 2a 78 20       	and    $0x20782a66,%eax
  402684:	2b 20                	sub    (%rax),%esp
  402686:	25 69 00 25 69       	and    $0x69250069,%eax
  40268b:	2c 20                	sub    $0x20,%al
  40268d:	25 69 00 62 61       	and    $0x61620069,%eax
  402692:	64 20 62 69          	and    %ah,%fs:0x69(%rdx)
  402696:	73 68                	jae    402700 <init_game.init_board+0x60>
  402698:	6f                   	outsl  %ds:(%rsi),(%dx)
  402699:	70 32                	jo     4026cd <init_game.init_board+0x2d>
  40269b:	0a 00                	or     (%rax),%al
  40269d:	00 00                	add    %al,(%rax)
	...

00000000004026a0 <init_game.init_board>:
  4026a0:	4c                   	rex.WR
  4026a1:	4e                   	rex.WRX
  4026a2:	47 55                	rex.RXB push %r13
  4026a4:	4b 55                	rex.WXB push %r13
  4026a6:	47                   	rex.RXB
  4026a7:	4e                   	rex.WRX
  4026a8:	4c 20 52 20          	rex.WR and %r10b,0x20(%rdx)
  4026ac:	20 20                	and    %ah,(%rax)
  4026ae:	20 20                	and    %ah,(%rax)
  4026b0:	42 20 50 50          	rex.X and %dl,0x50(%rax)
  4026b4:	50                   	push   %rax
  4026b5:	50                   	push   %rax
  4026b6:	50                   	push   %rax
  4026b7:	50                   	push   %rax
  4026b8:	50                   	push   %rax
  4026b9:	50                   	push   %rax
  4026ba:	50                   	push   %rax
  4026bb:	20 20                	and    %ah,(%rax)
  4026bd:	20 20                	and    %ah,(%rax)
  4026bf:	20 20                	and    %ah,(%rax)
  4026c1:	20 20                	and    %ah,(%rax)
  4026c3:	20 20                	and    %ah,(%rax)
  4026c5:	20 20                	and    %ah,(%rax)
  4026c7:	20 20                	and    %ah,(%rax)
  4026c9:	20 20                	and    %ah,(%rax)
  4026cb:	20 20                	and    %ah,(%rax)
  4026cd:	20 20                	and    %ah,(%rax)
  4026cf:	20 20                	and    %ah,(%rax)
  4026d1:	20 20                	and    %ah,(%rax)
  4026d3:	20 20                	and    %ah,(%rax)
  4026d5:	20 70 70             	and    %dh,0x70(%rax)
  4026d8:	70 70                	jo     40274a <init_game.init_board+0xaa>
  4026da:	70 70                	jo     40274c <init_game.init_board+0xac>
  4026dc:	70 70                	jo     40274e <init_game.init_board+0xae>
  4026de:	70 20                	jo     402700 <init_game.init_board+0x60>
  4026e0:	62                   	(bad)  
  4026e1:	20 20                	and    %ah,(%rax)
  4026e3:	20 20                	and    %ah,(%rax)
  4026e5:	20 72 20             	and    %dh,0x20(%rdx)
  4026e8:	6c                   	insb   (%dx),%es:(%rdi)
  4026e9:	6e                   	outsb  %ds:(%rsi),(%dx)
  4026ea:	67 75 6b             	addr32 jne 402758 <init_game.init_board+0xb8>
  4026ed:	75 67                	jne    402756 <init_game.init_board+0xb6>
  4026ef:	6e                   	outsb  %ds:(%rsi),(%dx)
  4026f0:	6c                   	insb   (%dx),%es:(%rdi)

Disassembly of section .eh_frame_hdr:

00000000004026f4 <.eh_frame_hdr>:
  4026f4:	01 1b                	add    %ebx,(%rbx)
  4026f6:	03 3b                	add    (%rbx),%edi
  4026f8:	90                   	nop
  4026f9:	00 00                	add    %al,(%rax)
  4026fb:	00 11                	add    %dl,(%rcx)
  4026fd:	00 00                	add    %al,(%rax)
  4026ff:	00 6c de ff          	add    %ch,-0x1(%rsi,%rbx,8)
  402703:	ff                   	(bad)  
  402704:	dc 00                	faddl  (%rax)
  402706:	00 00                	add    %al,(%rax)
  402708:	fc                   	cld    
  402709:	de ff                	fdivrp %st,%st(7)
  40270b:	ff ac 00 00 00 ec df 	ljmpq  *-0x20140000(%rax,%rax,1)
  402712:	ff                   	(bad)  
  402713:	ff 04 01             	incl   (%rcx,%rax,1)
  402716:	00 00                	add    %al,(%rax)
  402718:	ec                   	in     (%dx),%al
  402719:	ef                   	out    %eax,(%dx)
  40271a:	ff                   	(bad)  
  40271b:	ff 24 01             	jmpq   *(%rcx,%rax,1)
  40271e:	00 00                	add    %al,(%rax)
  402720:	0c f1                	or     $0xf1,%al
  402722:	ff                   	(bad)  
  402723:	ff 44 01 00          	incl   0x0(%rcx,%rax,1)
  402727:	00 0c f2             	add    %cl,(%rdx,%rsi,8)
  40272a:	ff                   	(bad)  
  40272b:	ff 64 01 00          	jmpq   *0x0(%rcx,%rax,1)
  40272f:	00 6c f2 ff          	add    %ch,-0x1(%rdx,%rsi,8)
  402733:	ff 84 01 00 00 bc f4 	incl   -0xb440000(%rcx,%rax,1)
  40273a:	ff                   	(bad)  
  40273b:	ff a4 01 00 00 6c f6 	jmpq   *-0x9940000(%rcx,%rax,1)
  402742:	ff                   	(bad)  
  402743:	ff c4                	inc    %esp
  402745:	01 00                	add    %eax,(%rax)
  402747:	00 6c f7 ff          	add    %ch,-0x1(%rdi,%rsi,8)
  40274b:	ff e4                	jmpq   *%rsp
  40274d:	01 00                	add    %eax,(%rax)
  40274f:	00 bc f7 ff ff 04 02 	add    %bh,0x204ffff(%rdi,%rsi,8)
  402756:	00 00                	add    %al,(%rax)
  402758:	6c                   	insb   (%dx),%es:(%rdi)
  402759:	f9                   	stc    
  40275a:	ff                   	(bad)  
  40275b:	ff 24 02             	jmpq   *(%rdx,%rax,1)
  40275e:	00 00                	add    %al,(%rax)
  402760:	3c fc                	cmp    $0xfc,%al
  402762:	ff                   	(bad)  
  402763:	ff 44 02 00          	incl   0x0(%rdx,%rax,1)
  402767:	00 bc fc ff ff 64 02 	add    %bh,0x264ffff(%rsp,%rdi,8)
  40276e:	00 00                	add    %al,(%rax)
  402770:	9c                   	pushfq 
  402771:	fd                   	std    
  402772:	ff                   	(bad)  
  402773:	ff 84 02 00 00 9c fe 	incl   -0x1640000(%rdx,%rax,1)
  40277a:	ff                   	(bad)  
  40277b:	ff a4 02 00 00 0c ff 	jmpq   *-0xf40000(%rdx,%rax,1)
  402782:	ff                   	(bad)  
  402783:	ff                   	(bad)  
  402784:	ec                   	in     (%dx),%al
  402785:	02 00                	add    (%rax),%al
	...

Disassembly of section .eh_frame:

0000000000402788 <__FRAME_END__-0x270>:
  402788:	14 00                	adc    $0x0,%al
  40278a:	00 00                	add    %al,(%rax)
  40278c:	00 00                	add    %al,(%rax)
  40278e:	00 00                	add    %al,(%rax)
  402790:	01 7a 52             	add    %edi,0x52(%rdx)
  402793:	00 01                	add    %al,(%rcx)
  402795:	78 10                	js     4027a7 <init_game.init_board+0x107>
  402797:	01 1b                	add    %ebx,(%rbx)
  402799:	0c 07                	or     $0x7,%al
  40279b:	08 90 01 07 10 14    	or     %dl,0x14100701(%rax)
  4027a1:	00 00                	add    %al,(%rax)
  4027a3:	00 1c 00             	add    %bl,(%rax,%rax,1)
  4027a6:	00 00                	add    %al,(%rax)
  4027a8:	48 de ff             	rex.W fdivrp %st,%st(7)
  4027ab:	ff 2a                	ljmpq  *(%rdx)
	...
  4027b5:	00 00                	add    %al,(%rax)
  4027b7:	00 14 00             	add    %dl,(%rax,%rax,1)
  4027ba:	00 00                	add    %al,(%rax)
  4027bc:	00 00                	add    %al,(%rax)
  4027be:	00 00                	add    %al,(%rax)
  4027c0:	01 7a 52             	add    %edi,0x52(%rdx)
  4027c3:	00 01                	add    %al,(%rcx)
  4027c5:	78 10                	js     4027d7 <init_game.init_board+0x137>
  4027c7:	01 1b                	add    %ebx,(%rbx)
  4027c9:	0c 07                	or     $0x7,%al
  4027cb:	08 90 01 00 00 24    	or     %dl,0x24000001(%rax)
  4027d1:	00 00                	add    %al,(%rax)
  4027d3:	00 1c 00             	add    %bl,(%rax,%rax,1)
  4027d6:	00 00                	add    %al,(%rax)
  4027d8:	88 dd                	mov    %bl,%ch
  4027da:	ff                   	(bad)  
  4027db:	ff 90 00 00 00 00    	callq  *0x0(%rax)
  4027e1:	0e                   	(bad)  
  4027e2:	10 46 0e             	adc    %al,0xe(%rsi)
  4027e5:	18 4a 0f             	sbb    %cl,0xf(%rdx)
  4027e8:	0b 77 08             	or     0x8(%rdi),%esi
  4027eb:	80 00 3f             	addb   $0x3f,(%rax)
  4027ee:	1a 3b                	sbb    (%rbx),%bh
  4027f0:	2a 33                	sub    (%rbx),%dh
  4027f2:	24 22                	and    $0x22,%al
  4027f4:	00 00                	add    %al,(%rax)
  4027f6:	00 00                	add    %al,(%rax)
  4027f8:	1c 00                	sbb    $0x0,%al
  4027fa:	00 00                	add    %al,(%rax)
  4027fc:	44 00 00             	add    %r8b,(%rax)
  4027ff:	00 e0                	add    %ah,%al
  402801:	de ff                	fdivrp %st,%st(7)
  402803:	ff f7                	push   %rdi
  402805:	0f 00 00             	sldt   (%rax)
  402808:	00 41 0e             	add    %al,0xe(%rcx)
  40280b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  402811:	00 00                	add    %al,(%rax)
  402813:	00 00                	add    %al,(%rax)
  402815:	00 00                	add    %al,(%rax)
  402817:	00 1c 00             	add    %bl,(%rax,%rax,1)
  40281a:	00 00                	add    %al,(%rax)
  40281c:	64 00 00             	add    %al,%fs:(%rax)
  40281f:	00 c0                	add    %al,%al
  402821:	ee                   	out    %al,(%dx)
  402822:	ff                   	(bad)  
  402823:	ff 14 01             	callq  *(%rcx,%rax,1)
  402826:	00 00                	add    %al,(%rax)
  402828:	00 41 0e             	add    %al,0xe(%rcx)
  40282b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  402831:	00 00                	add    %al,(%rax)
  402833:	00 00                	add    %al,(%rax)
  402835:	00 00                	add    %al,(%rax)
  402837:	00 1c 00             	add    %bl,(%rax,%rax,1)
  40283a:	00 00                	add    %al,(%rax)
  40283c:	84 00                	test   %al,(%rax)
  40283e:	00 00                	add    %al,(%rax)
  402840:	c0 ef ff             	shr    $0xff,%bh
  402843:	ff                   	(bad)  
  402844:	fb                   	sti    
  402845:	00 00                	add    %al,(%rax)
  402847:	00 00                	add    %al,(%rax)
  402849:	41 0e                	rex.B (bad) 
  40284b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  402851:	00 00                	add    %al,(%rax)
  402853:	00 00                	add    %al,(%rax)
  402855:	00 00                	add    %al,(%rax)
  402857:	00 1c 00             	add    %bl,(%rax,%rax,1)
  40285a:	00 00                	add    %al,(%rax)
  40285c:	a4                   	movsb  %ds:(%rsi),%es:(%rdi)
  40285d:	00 00                	add    %al,(%rax)
  40285f:	00 a0 f0 ff ff 56    	add    %ah,0x56fffff0(%rax)
  402865:	00 00                	add    %al,(%rax)
  402867:	00 00                	add    %al,(%rax)
  402869:	41 0e                	rex.B (bad) 
  40286b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  402871:	00 00                	add    %al,(%rax)
  402873:	00 00                	add    %al,(%rax)
  402875:	00 00                	add    %al,(%rax)
  402877:	00 1c 00             	add    %bl,(%rax,%rax,1)
  40287a:	00 00                	add    %al,(%rax)
  40287c:	c4                   	(bad)  
  40287d:	00 00                	add    %al,(%rax)
  40287f:	00 e0                	add    %ah,%al
  402881:	f0 ff                	lock (bad) 
  402883:	ff 43 02             	incl   0x2(%rbx)
  402886:	00 00                	add    %al,(%rax)
  402888:	00 41 0e             	add    %al,0xe(%rcx)
  40288b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  402891:	00 00                	add    %al,(%rax)
  402893:	00 00                	add    %al,(%rax)
  402895:	00 00                	add    %al,(%rax)
  402897:	00 1c 00             	add    %bl,(%rax,%rax,1)
  40289a:	00 00                	add    %al,(%rax)
  40289c:	e4 00                	in     $0x0,%al
  40289e:	00 00                	add    %al,(%rax)
  4028a0:	10 f3                	adc    %dh,%bl
  4028a2:	ff                   	(bad)  
  4028a3:	ff ac 01 00 00 00 41 	ljmpq  *0x41000000(%rcx,%rax,1)
  4028aa:	0e                   	(bad)  
  4028ab:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  4028b1:	00 00                	add    %al,(%rax)
  4028b3:	00 00                	add    %al,(%rax)
  4028b5:	00 00                	add    %al,(%rax)
  4028b7:	00 1c 00             	add    %bl,(%rax,%rax,1)
  4028ba:	00 00                	add    %al,(%rax)
  4028bc:	04 01                	add    $0x1,%al
  4028be:	00 00                	add    %al,(%rax)
  4028c0:	a0 f4 ff ff f6 00 00 	movabs 0xf6fffff4,%al
  4028c7:	00 00 
  4028c9:	41 0e                	rex.B (bad) 
  4028cb:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  4028d1:	00 00                	add    %al,(%rax)
  4028d3:	00 00                	add    %al,(%rax)
  4028d5:	00 00                	add    %al,(%rax)
  4028d7:	00 1c 00             	add    %bl,(%rax,%rax,1)
  4028da:	00 00                	add    %al,(%rax)
  4028dc:	24 01                	and    $0x1,%al
  4028de:	00 00                	add    %al,(%rax)
  4028e0:	80 f5 ff             	xor    $0xff,%ch
  4028e3:	ff 4e 00             	decl   0x0(%rsi)
  4028e6:	00 00                	add    %al,(%rax)
  4028e8:	00 41 0e             	add    %al,0xe(%rcx)
  4028eb:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  4028f1:	00 00                	add    %al,(%rax)
  4028f3:	00 00                	add    %al,(%rax)
  4028f5:	00 00                	add    %al,(%rax)
  4028f7:	00 1c 00             	add    %bl,(%rax,%rax,1)
  4028fa:	00 00                	add    %al,(%rax)
  4028fc:	44 01 00             	add    %r8d,(%rax)
  4028ff:	00 b0 f5 ff ff a5    	add    %dh,-0x5a00000b(%rax)
  402905:	01 00                	add    %eax,(%rax)
  402907:	00 00                	add    %al,(%rax)
  402909:	41 0e                	rex.B (bad) 
  40290b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  402911:	00 00                	add    %al,(%rax)
  402913:	00 00                	add    %al,(%rax)
  402915:	00 00                	add    %al,(%rax)
  402917:	00 1c 00             	add    %bl,(%rax,%rax,1)
  40291a:	00 00                	add    %al,(%rax)
  40291c:	64 01 00             	add    %eax,%fs:(%rax)
  40291f:	00 40 f7             	add    %al,-0x9(%rax)
  402922:	ff                   	(bad)  
  402923:	ff cb                	dec    %ebx
  402925:	02 00                	add    (%rax),%al
  402927:	00 00                	add    %al,(%rax)
  402929:	41 0e                	rex.B (bad) 
  40292b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  402931:	00 00                	add    %al,(%rax)
  402933:	00 00                	add    %al,(%rax)
  402935:	00 00                	add    %al,(%rax)
  402937:	00 1c 00             	add    %bl,(%rax,%rax,1)
  40293a:	00 00                	add    %al,(%rax)
  40293c:	84 01                	test   %al,(%rcx)
  40293e:	00 00                	add    %al,(%rax)
  402940:	f0 f9                	lock stc 
  402942:	ff                   	(bad)  
  402943:	ff 74 00 00          	pushq  0x0(%rax,%rax,1)
  402947:	00 00                	add    %al,(%rax)
  402949:	41 0e                	rex.B (bad) 
  40294b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  402951:	00 00                	add    %al,(%rax)
  402953:	00 00                	add    %al,(%rax)
  402955:	00 00                	add    %al,(%rax)
  402957:	00 1c 00             	add    %bl,(%rax,%rax,1)
  40295a:	00 00                	add    %al,(%rax)
  40295c:	a4                   	movsb  %ds:(%rsi),%es:(%rdi)
  40295d:	01 00                	add    %eax,(%rax)
  40295f:	00 50 fa             	add    %dl,-0x6(%rax)
  402962:	ff                   	(bad)  
  402963:	ff d5                	callq  *%rbp
  402965:	00 00                	add    %al,(%rax)
  402967:	00 00                	add    %al,(%rax)
  402969:	41 0e                	rex.B (bad) 
  40296b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  402971:	00 00                	add    %al,(%rax)
  402973:	00 00                	add    %al,(%rax)
  402975:	00 00                	add    %al,(%rax)
  402977:	00 1c 00             	add    %bl,(%rax,%rax,1)
  40297a:	00 00                	add    %al,(%rax)
  40297c:	c4 01 00 00          	(bad)  
  402980:	10 fb                	adc    %bh,%bl
  402982:	ff                   	(bad)  
  402983:	ff f7                	push   %rdi
  402985:	00 00                	add    %al,(%rax)
  402987:	00 00                	add    %al,(%rax)
  402989:	41 0e                	rex.B (bad) 
  40298b:	10 86 02 43 0d 06    	adc    %al,0x60d4302(%rsi)
  402991:	00 00                	add    %al,(%rax)
  402993:	00 00                	add    %al,(%rax)
  402995:	00 00                	add    %al,(%rax)
  402997:	00 44 00 00          	add    %al,0x0(%rax,%rax,1)
  40299b:	00 e4                	add    %ah,%ah
  40299d:	01 00                	add    %eax,(%rax)
  40299f:	00 f0                	add    %dh,%al
  4029a1:	fb                   	sti    
  4029a2:	ff                   	(bad)  
  4029a3:	ff 65 00             	jmpq   *0x0(%rbp)
  4029a6:	00 00                	add    %al,(%rax)
  4029a8:	00 42 0e             	add    %al,0xe(%rdx)
  4029ab:	10 8f 02 45 0e 18    	adc    %cl,0x180e4502(%rdi)
  4029b1:	8e 03                	mov    (%rbx),%es
  4029b3:	45 0e                	rex.RB (bad) 
  4029b5:	20 8d 04 45 0e 28    	and    %cl,0x280e4504(%rbp)
  4029bb:	8c 05 48 0e 30 86    	mov    %es,-0x79cff1b8(%rip)        # ffffffff86703809 <_end+0xffffffff86100799>
  4029c1:	06                   	(bad)  
  4029c2:	48 0e                	rex.W (bad) 
  4029c4:	38 83 07 4d 0e 40    	cmp    %al,0x400e4d07(%rbx)
  4029ca:	6c                   	insb   (%dx),%es:(%rdi)
  4029cb:	0e                   	(bad)  
  4029cc:	38 41 0e             	cmp    %al,0xe(%rcx)
  4029cf:	30 41 0e             	xor    %al,0xe(%rcx)
  4029d2:	28 42 0e             	sub    %al,0xe(%rdx)
  4029d5:	20 42 0e             	and    %al,0xe(%rdx)
  4029d8:	18 42 0e             	sbb    %al,0xe(%rdx)
  4029db:	10 42 0e             	adc    %al,0xe(%rdx)
  4029de:	08 00                	or     %al,(%rax)
  4029e0:	14 00                	adc    $0x0,%al
  4029e2:	00 00                	add    %al,(%rax)
  4029e4:	2c 02                	sub    $0x2,%al
  4029e6:	00 00                	add    %al,(%rax)
  4029e8:	18 fc                	sbb    %bh,%ah
  4029ea:	ff                   	(bad)  
  4029eb:	ff 02                	incl   (%rdx)
	...

00000000004029f8 <__FRAME_END__>:
  4029f8:	00 00                	add    %al,(%rax)
	...

Disassembly of section .init_array:

0000000000602e10 <__frame_dummy_init_array_entry>:
  602e10:	b0 06                	mov    $0x6,%al
  602e12:	40 00 00             	add    %al,(%rax)
  602e15:	00 00                	add    %al,(%rax)
	...

Disassembly of section .fini_array:

0000000000602e18 <__do_global_dtors_aux_fini_array_entry>:
  602e18:	90                   	nop
  602e19:	06                   	(bad)  
  602e1a:	40 00 00             	add    %al,(%rax)
  602e1d:	00 00                	add    %al,(%rax)
	...

Disassembly of section .jcr:

0000000000602e20 <__JCR_END__>:
	...

Disassembly of section .dynamic:

0000000000602e28 <_DYNAMIC>:
  602e28:	01 00                	add    %eax,(%rax)
  602e2a:	00 00                	add    %al,(%rax)
  602e2c:	00 00                	add    %al,(%rax)
  602e2e:	00 00                	add    %al,(%rax)
  602e30:	01 00                	add    %eax,(%rax)
  602e32:	00 00                	add    %al,(%rax)
  602e34:	00 00                	add    %al,(%rax)
  602e36:	00 00                	add    %al,(%rax)
  602e38:	0c 00                	or     $0x0,%al
  602e3a:	00 00                	add    %al,(%rax)
  602e3c:	00 00                	add    %al,(%rax)
  602e3e:	00 00                	add    %al,(%rax)
  602e40:	38 05 40 00 00 00    	cmp    %al,0x40(%rip)        # 602e86 <_DYNAMIC+0x5e>
  602e46:	00 00                	add    %al,(%rax)
  602e48:	0d 00 00 00 00       	or     $0x0,%eax
  602e4d:	00 00                	add    %al,(%rax)
  602e4f:	00 04 26             	add    %al,(%rsi,%riz,1)
  602e52:	40 00 00             	add    %al,(%rax)
  602e55:	00 00                	add    %al,(%rax)
  602e57:	00 19                	add    %bl,(%rcx)
  602e59:	00 00                	add    %al,(%rax)
  602e5b:	00 00                	add    %al,(%rax)
  602e5d:	00 00                	add    %al,(%rax)
  602e5f:	00 10                	add    %dl,(%rax)
  602e61:	2e                   	cs
  602e62:	60                   	(bad)  
  602e63:	00 00                	add    %al,(%rax)
  602e65:	00 00                	add    %al,(%rax)
  602e67:	00 1b                	add    %bl,(%rbx)
  602e69:	00 00                	add    %al,(%rax)
  602e6b:	00 00                	add    %al,(%rax)
  602e6d:	00 00                	add    %al,(%rax)
  602e6f:	00 08                	add    %cl,(%rax)
  602e71:	00 00                	add    %al,(%rax)
  602e73:	00 00                	add    %al,(%rax)
  602e75:	00 00                	add    %al,(%rax)
  602e77:	00 1a                	add    %bl,(%rdx)
  602e79:	00 00                	add    %al,(%rax)
  602e7b:	00 00                	add    %al,(%rax)
  602e7d:	00 00                	add    %al,(%rax)
  602e7f:	00 18                	add    %bl,(%rax)
  602e81:	2e                   	cs
  602e82:	60                   	(bad)  
  602e83:	00 00                	add    %al,(%rax)
  602e85:	00 00                	add    %al,(%rax)
  602e87:	00 1c 00             	add    %bl,(%rax,%rax,1)
  602e8a:	00 00                	add    %al,(%rax)
  602e8c:	00 00                	add    %al,(%rax)
  602e8e:	00 00                	add    %al,(%rax)
  602e90:	08 00                	or     %al,(%rax)
  602e92:	00 00                	add    %al,(%rax)
  602e94:	00 00                	add    %al,(%rax)
  602e96:	00 00                	add    %al,(%rax)
  602e98:	f5                   	cmc    
  602e99:	fe                   	(bad)  
  602e9a:	ff 6f 00             	ljmpq  *0x0(%rdi)
  602e9d:	00 00                	add    %al,(%rax)
  602e9f:	00 98 02 40 00 00    	add    %bl,0x4002(%rax)
  602ea5:	00 00                	add    %al,(%rax)
  602ea7:	00 05 00 00 00 00    	add    %al,0x0(%rip)        # 602ead <_DYNAMIC+0x85>
  602ead:	00 00                	add    %al,(%rax)
  602eaf:	00 90 03 40 00 00    	add    %dl,0x4003(%rax)
  602eb5:	00 00                	add    %al,(%rax)
  602eb7:	00 06                	add    %al,(%rsi)
  602eb9:	00 00                	add    %al,(%rax)
  602ebb:	00 00                	add    %al,(%rax)
  602ebd:	00 00                	add    %al,(%rax)
  602ebf:	00 b8 02 40 00 00    	add    %bh,0x4002(%rax)
  602ec5:	00 00                	add    %al,(%rax)
  602ec7:	00 0a                	add    %cl,(%rdx)
  602ec9:	00 00                	add    %al,(%rax)
  602ecb:	00 00                	add    %al,(%rax)
  602ecd:	00 00                	add    %al,(%rax)
  602ecf:	00 79 00             	add    %bh,0x0(%rcx)
  602ed2:	00 00                	add    %al,(%rax)
  602ed4:	00 00                	add    %al,(%rax)
  602ed6:	00 00                	add    %al,(%rax)
  602ed8:	0b 00                	or     (%rax),%eax
  602eda:	00 00                	add    %al,(%rax)
  602edc:	00 00                	add    %al,(%rax)
  602ede:	00 00                	add    %al,(%rax)
  602ee0:	18 00                	sbb    %al,(%rax)
  602ee2:	00 00                	add    %al,(%rax)
  602ee4:	00 00                	add    %al,(%rax)
  602ee6:	00 00                	add    %al,(%rax)
  602ee8:	15 00 00 00 00       	adc    $0x0,%eax
	...
  602ef5:	00 00                	add    %al,(%rax)
  602ef7:	00 03                	add    %al,(%rbx)
	...
  602f01:	30 60 00             	xor    %ah,0x0(%rax)
  602f04:	00 00                	add    %al,(%rax)
  602f06:	00 00                	add    %al,(%rax)
  602f08:	02 00                	add    (%rax),%al
  602f0a:	00 00                	add    %al,(%rax)
  602f0c:	00 00                	add    %al,(%rax)
  602f0e:	00 00                	add    %al,(%rax)
  602f10:	c0 00 00             	rolb   $0x0,(%rax)
  602f13:	00 00                	add    %al,(%rax)
  602f15:	00 00                	add    %al,(%rax)
  602f17:	00 14 00             	add    %dl,(%rax,%rax,1)
  602f1a:	00 00                	add    %al,(%rax)
  602f1c:	00 00                	add    %al,(%rax)
  602f1e:	00 00                	add    %al,(%rax)
  602f20:	07                   	(bad)  
  602f21:	00 00                	add    %al,(%rax)
  602f23:	00 00                	add    %al,(%rax)
  602f25:	00 00                	add    %al,(%rax)
  602f27:	00 17                	add    %dl,(%rdi)
  602f29:	00 00                	add    %al,(%rax)
  602f2b:	00 00                	add    %al,(%rax)
  602f2d:	00 00                	add    %al,(%rax)
  602f2f:	00 78 04             	add    %bh,0x4(%rax)
  602f32:	40 00 00             	add    %al,(%rax)
  602f35:	00 00                	add    %al,(%rax)
  602f37:	00 07                	add    %al,(%rdi)
  602f39:	00 00                	add    %al,(%rax)
  602f3b:	00 00                	add    %al,(%rax)
  602f3d:	00 00                	add    %al,(%rax)
  602f3f:	00 60 04             	add    %ah,0x4(%rax)
  602f42:	40 00 00             	add    %al,(%rax)
  602f45:	00 00                	add    %al,(%rax)
  602f47:	00 08                	add    %cl,(%rax)
  602f49:	00 00                	add    %al,(%rax)
  602f4b:	00 00                	add    %al,(%rax)
  602f4d:	00 00                	add    %al,(%rax)
  602f4f:	00 18                	add    %bl,(%rax)
  602f51:	00 00                	add    %al,(%rax)
  602f53:	00 00                	add    %al,(%rax)
  602f55:	00 00                	add    %al,(%rax)
  602f57:	00 09                	add    %cl,(%rcx)
  602f59:	00 00                	add    %al,(%rax)
  602f5b:	00 00                	add    %al,(%rax)
  602f5d:	00 00                	add    %al,(%rax)
  602f5f:	00 18                	add    %bl,(%rax)
  602f61:	00 00                	add    %al,(%rax)
  602f63:	00 00                	add    %al,(%rax)
  602f65:	00 00                	add    %al,(%rax)
  602f67:	00 fe                	add    %bh,%dh
  602f69:	ff                   	(bad)  
  602f6a:	ff 6f 00             	ljmpq  *0x0(%rdi)
  602f6d:	00 00                	add    %al,(%rax)
  602f6f:	00 20                	add    %ah,(%rax)
  602f71:	04 40                	add    $0x40,%al
  602f73:	00 00                	add    %al,(%rax)
  602f75:	00 00                	add    %al,(%rax)
  602f77:	00 ff                	add    %bh,%bh
  602f79:	ff                   	(bad)  
  602f7a:	ff 6f 00             	ljmpq  *0x0(%rdi)
  602f7d:	00 00                	add    %al,(%rax)
  602f7f:	00 01                	add    %al,(%rcx)
  602f81:	00 00                	add    %al,(%rax)
  602f83:	00 00                	add    %al,(%rax)
  602f85:	00 00                	add    %al,(%rax)
  602f87:	00 f0                	add    %dh,%al
  602f89:	ff                   	(bad)  
  602f8a:	ff 6f 00             	ljmpq  *0x0(%rdi)
  602f8d:	00 00                	add    %al,(%rax)
  602f8f:	00 0a                	add    %cl,(%rdx)
  602f91:	04 40                	add    $0x40,%al
	...

Disassembly of section .got:

0000000000602ff8 <.got>:
	...

Disassembly of section .got.plt:

0000000000603000 <_GLOBAL_OFFSET_TABLE_>:
  603000:	28 2e                	sub    %ch,(%rsi)
  603002:	60                   	(bad)  
	...
  603017:	00 76 05             	add    %dh,0x5(%rsi)
  60301a:	40 00 00             	add    %al,(%rax)
  60301d:	00 00                	add    %al,(%rax)
  60301f:	00 86 05 40 00 00    	add    %al,0x4005(%rsi)
  603025:	00 00                	add    %al,(%rax)
  603027:	00 96 05 40 00 00    	add    %dl,0x4005(%rsi)
  60302d:	00 00                	add    %al,(%rax)
  60302f:	00 a6 05 40 00 00    	add    %ah,0x4005(%rsi)
  603035:	00 00                	add    %al,(%rax)
  603037:	00 b6 05 40 00 00    	add    %dh,0x4005(%rsi)
  60303d:	00 00                	add    %al,(%rax)
  60303f:	00 c6                	add    %al,%dh
  603041:	05 40 00 00 00       	add    $0x40,%eax
  603046:	00 00                	add    %al,(%rax)
  603048:	d6                   	(bad)  
  603049:	05 40 00 00 00       	add    $0x40,%eax
  60304e:	00 00                	add    %al,(%rax)
  603050:	e6 05                	out    %al,$0x5
  603052:	40 00 00             	add    %al,(%rax)
  603055:	00 00                	add    %al,(%rax)
	...

Disassembly of section .data:

0000000000603058 <__data_start>:
	...

0000000000603060 <__dso_handle>:
	...

Disassembly of section .bss:

0000000000603068 <__bss_start>:
	...

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	47                   	rex.RXB
   1:	43                   	rex.XB
   2:	43 3a 20             	rex.XB cmp (%r8),%spl
   5:	28 55 62             	sub    %dl,0x62(%rbp)
   8:	75 6e                	jne    78 <_init-0x4004c0>
   a:	74 75                	je     81 <_init-0x4004b7>
   c:	20 34 2e             	and    %dh,(%rsi,%rbp,1)
   f:	38 2e                	cmp    %ch,(%rsi)
  11:	32 2d 31 39 75 62    	xor    0x62753931(%rip),%ch        # 62753948 <_end+0x621508d8>
  17:	75 6e                	jne    87 <_init-0x4004b1>
  19:	74 75                	je     90 <_init-0x4004a8>
  1b:	31 29                	xor    %ebp,(%rcx)
  1d:	20 34 2e             	and    %dh,(%rsi,%rbp,1)
  20:	38 2e                	cmp    %ch,(%rsi)
  22:	32 00                	xor    (%rax),%al
  24:	55                   	push   %rbp
  25:	62                   	(bad)  
  26:	75 6e                	jne    96 <_init-0x4004a2>
  28:	74 75                	je     9f <_init-0x400499>
  2a:	20 63 6c             	and    %ah,0x6c(%rbx)
  2d:	61                   	(bad)  
  2e:	6e                   	outsb  %ds:(%rsi),(%dx)
  2f:	67 20 76 65          	and    %dh,0x65(%esi)
  33:	72 73                	jb     a8 <_init-0x400490>
  35:	69 6f 6e 20 33 2e 34 	imul   $0x342e3320,0x6e(%rdi),%ebp
  3c:	2d 31 75 62 75       	sub    $0x75627531,%eax
  41:	6e                   	outsb  %ds:(%rsi),(%dx)
  42:	74 75                	je     b9 <_init-0x40047f>
  44:	33 20                	xor    (%rax),%esp
  46:	28 74 61 67          	sub    %dh,0x67(%rcx,%riz,2)
  4a:	73 2f                	jae    7b <_init-0x4004bd>
  4c:	52                   	push   %rdx
  4d:	45                   	rex.RB
  4e:	4c                   	rex.WR
  4f:	45                   	rex.RB
  50:	41 53                	push   %r11
  52:	45 5f                	rex.RB pop %r15
  54:	33 34 2f             	xor    (%rdi,%rbp,1),%esi
  57:	66 69 6e 61 6c 29    	imul   $0x296c,0x61(%rsi),%bp
  5d:	20 28                	and    %ch,(%rax)
  5f:	62 61                	(bad)  
  61:	73 65                	jae    c8 <_init-0x400470>
  63:	64 20 6f 6e          	and    %ch,%fs:0x6e(%rdi)
  67:	20 4c 4c 56          	and    %cl,0x56(%rsp,%rcx,2)
  6b:	4d 20 33             	rex.WRB and %r14b,(%r11)
  6e:	2e                   	cs
  6f:	34 29                	xor    $0x29,%al
	...
