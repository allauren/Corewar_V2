#by gsmith, it's something
#2018

.name		"jaures"
.comment	"Le capitalisme porte en lui la guerre comme la nuee porte l'orage"


welllive:
	live	%42
	zjmp	%:welllive

start:
	sti		r1, %:welllive, %1
	sti		r1, %:north, %1
	sti		r1, %:spawn_n, %1
	sti		r1, %:makezork, %1
	sti		r1, %:spawn_s, %1
	sti		r1, %:south, %1
	ld		%0, r16
	fork	%:delay
	zjmp	%:spawn_n

north:
	live	%42
	st		r16, -510
	st		r16, -508
	st		r16, -506
	st		r16, -504
	st		r16, -502
	st		r16, -500
	st		r16, -498
	st		r16, -496
	st		r16, -494
	st		r16, -492
	st		r16, -490
	st		r16, -488
	st		r16, -486
	st		r16, -484
	st		r16, -482
	st		r16, -480
	st		r16, -478
	st		r16, -476
	st		r16, -474
	st		r16, -472
	st		r16, -470
	st		r16, -468
	st		r16, -466
	st		r16, -464
	st		r16, -462
	st		r16, -460
	st		r16, -458
	st		r16, -456
	st		r16, -454
	st		r16, -452
	st		r16, -450
	st		r16, -448
	st		r16, -446
	st		r16, -444
	st		r16, -442
	st		r16, -440
	st		r16, -438
	st		r16, -436
	st		r16, -434
	st		r16, -432
	st		r16, -430
	st		r16, -428
	st		r16, -426
	st		r16, -424
	st		r16, -422
	st		r16, -420
	st		r16, -418
	st		r16, -416
	st		r16, -414
	st		r16, -412
	st		r16, -410
	st		r16, -408
	zjmp	%:north

spawn_n:
	live	%42
	fork	%:north
	zjmp	%:spawn_n

delay:
	ld		%209756937, r2
makezork:
	live	%42
forkzork:
	fork	%:pre_spawn_s
	zjmp	%:makezork
	st		r2, :forkzork
	ld		%0, r16
	zjmp	%:makezork

pre_spawn_s:
	ld		%0, r2
spawn_s:
	live	%42
	fork	%:south
	zjmp	%:spawn_s

south:
	live	%42
	st		r16, 408
	st		r16, 410
	st		r16, 412
	st		r16, 414
	st		r16, 416
	st		r16, 418
	st		r16, 420
	st		r16, 422
	st		r16, 424
	st		r16, 426
	st		r16, 428
	st		r16, 430
	st		r16, 432
	st		r16, 434
	st		r16, 436
	st		r16, 438
	st		r16, 440
	st		r16, 442
	st		r16, 444
	st		r16, 446
	st		r16, 448
	st		r16, 450
	st		r16, 452
	st		r16, 454
	st		r16, 456
	st		r16, 458
	st		r16, 460
	st		r16, 462
	st		r16, 464
	st		r16, 466
	st		r16, 468
	st		r16, 470
	st		r16, 472
	st		r16, 474
	st		r16, 476
	st		r16, 478
	st		r16, 480
	st		r16, 482
	st		r16, 484
	st		r16, 486
	st		r16, 488
	st		r16, 490
	st		r16, 492
	st		r16, 494
	st		r16, 496
	st		r16, 498
	st		r16, 500
	st		r16, 502
	st		r16, 504
	st		r16, 506
	st		r16, 508
	st		r16, 510
	zjmp	%:south
