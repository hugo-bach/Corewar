.name		"helltrain"
.comment	"choochoo,motherf*****s !"

entry:
	sti		r1,%:cc4l,%1
    sti	r1, %:beegees_gen, %1
	sti		r1,%:beegees,%1
	sti		r1,%:cc_spawn,%1
	sti		r1,%:wall,%1
	sti		r1,%:cc_spawn,%1
	sti		r1,%:cc4,%9
	sti		r1,%:cc4,%17
	sti		r1,%:cc4l,%1
	sti		r1,%:cc4ld,%2
	sti		r1,%:cc3,%1
	sti		r1,%:cc3,%9
	sti		r1,%:cc2,%1
	ld		%0,r16
	fork	%:cc_spawn

wall_prep:
	ld		%0,r2
	ld		%0,r16

wall:
	live	%490
	st		r2,-24
	st		r2,-33
	st		r2,42
	st		r2,51
	st		r2,60
	st		r2,69
	st		r2,78
	st		r2,87
	st		r2,96
	st		r2,105
	st		r2,114
	st		r2,123
	st		r2,132
	st		r2,141
	st		r2,150
	st		r2,159
	st		r2,168
	st		r2,177
	st		r2,186
	st		r2,195
	st		r2,204
	st		r2,213
	st		r2,222
	st		r2,231
	st		r2,240
	st		r2,249
	st		r2,258
	st		r2,267
	st		r2,276
	st		r2,285
	st		r2,294
	st		r2,303
	st		r2,312
	st		r2,321
	st		r2,330
	st		r2,339
	st		r2,348
	st		r2,357
	st		r2,366
	st		r2,375
	st		r2,384
	st		r2,393
	st		r2,402
	st		r2,411
	st		r2,420
	st		r2,429
	st		r2,438
	st		r2,447
	st		r2,456
	st		r2,465
	st		r2,474
	st		r2,483
	st		r2,492
	st		r2,501
	st		r10,15
	zjmp	%:wall

beegees_gen:
	live	%4239
	fork	%:beegees_gen
	ld		%0,r16

beegees:
	live	%3442
	zjmp	%:beegees

cc_spawn:
	live	%43203
	zjmp	%3 #test
	fork	%:cc_spawn

cc4:
	live	%43290
	fork	%:cc3
	live	%34011
	fork	%:cc2
	live	%45905
	fork	%:cc1
cc4ld:
	ld		%0,r2
	ld		%25188,r3
	ld		%0,r16
cc4l:
	live	%49304
	ld		%0,r16
	zjmp	%:choochoo

cc2:
	live	%43423
	fork	%:wall_prep
	ld		%25188,r2
	ld		%38610,r3
	ld		%0,r16
	ld		%0,r16
	zjmp	%:choochoo

cc3:
	live	%42390
	fork	%:cc4
	live	%40932
	fork	%:beegees_gen
	ld		%42949,r2
	ld		%43643,r3
	ld		%0,r16
	ld		%0,r16
	ld		%0,r16
	zjmp	%:choochoo

cc1:
	ld		%57672,r2
	ld		%31899,r3
	ld		%0,r16
	zjmp	%:choochoo

choochoo:
	st		r2,15
	st		r3,1
cc_live:
	live	%0
