build/dukenukem.elf: \
    build/header.o \
    build/assets/boot.o \
    build/src/entry.o \
    build/src/main.o \
    build/src/sched.o \
    build/asm/control.o \
    build/asm/game1.o \
    build/asm/control2.o \
    build/asm/game2.o \
    build/asm/logo.o \
    build/asm/boss2.o \
    build/asm/sound1.o \
    build/asm/sound2.o \
    build/src/rend1.o \
    build/asm/rend2.o \
    build/src/getangle.o \
    build/src/draw.o \
    build/src/tileinfo.o \
    build/src/rnc.o \
    build/src/display1.o \
    build/src/cache1d.o \
    build/src/display2.o \
    build/src/actors1.o \
    build/src/actors2.o \
    build/src/actors3.o \
    build/src/gamedef.o \
    build/src/script.o \
    build/src/engine.o \
    build/src/game3.o \
    build/src/game4.o \
    build/src/player1.o \
    build/src/player2.o \
    build/src/player3.o \
    build/src/premap.o \
    build/src/sector.o \
    build/src/board.o \
    build/src/tile.o \
    build/src/tables.o \
    build/src/dukebot.o \
    build/asm/menues.o \
    build/src/libultra/io/viblack.o \
    build/src/libultra/os/initialize.o \
    build/src/libultra/os/createthread.o \
    build/src/libultra/os/startthread.o \
    build/src/libultra/io/pimgr.o \
    build/src/libultra/os/setthreadpri.o \
    build/asm/libultra/os/writebackdcacheall.o \
    build/src/libultra/io/pigetstat.o \
    build/src/libultra/io/pidma.o \
    build/src/libultra/os/recvmesg.o \
    build/src/libultra/os/gettime.o \
    build/src/libultra/os/sendmesg.o \
    build/src/libultra/os/createmesgqueue.o \
    build/src/libultra/libc/ll.o \
    build/src/libultra/io/visetyscale.o \
    build/src/libultra/io/vimgr.o \
    build/src/libultra/io/vitbl.o \
    build/asm/libultra/unk1.o \
    build/src/libultra/io/visetmode.o \
    build/src/libultra/io/visetspecial.o \
    build/src/libultra/os/seteventmesg.o \
    build/src/libultra/io/visetevent.o \
    build/asm/libultra/os/setintmask.o \
    build/src/libultra/io/sptaskyielded.o \
    build/src/libultra/io/vigetcurrframebuf.o \
    build/src/libultra/io/vigetnextframebuf.o \
    build/src/libultra/io/viswapbuf.o \
    build/src/libultra/io/sptask.o \
    build/src/libultra/io/dpsetnextbuf.o \
    build/src/libultra/io/sptaskyield.o \
    build/src/libultra/io/contreaddata.o \
    build/src/libultra/io/controller.o \
    build/src/libultra/io/pfsinitpak.o \
    build/src/libultra/io/pfsnumfiles.o \
    build/src/libultra/io/pfsfreeblocks.o \
    build/src/libultra/io/motor.o \
    build/src/libultra/gu/translate.o \
    build/src/libultra/gu/scale.o \
    build/src/libultra/libc/sprintf.o \
    build/src/libultra/libc/string.o \
    build/src/libultra/io/pfsfilestate.o \
    build/src/libultra/os/yieldthread.o \
    build/src/libultra/io/pfsdeletefile.o \
    build/src/libultra/io/pfsallocatefile.o \
    build/src/libultra/io/pfsreadwritefile.o \
    build/src/libultra/io/pfssearchfile.o \
    build/src/libultra/io/pfsrepairid.o \
    build/src/libultra/gu/rotate.o \
    build/src/libultra/os/virtualtophysical.o \
    build/src/libultra/audio/sl.o \
    build/src/libultra/audio/heapalloc.o \
    build/src/libultra/audio/heapinit.o \
    build/src/libultra/io/aisetfreq.o \
    build/src/libultra/audio/sndplayer.o \
    build/src/libultra/audio/bnkf.o \
    build/src/libultra/audio/sndpallocate.o \
    build/src/libultra/audio/csplayer.o \
    build/src/libultra/audio/seqpsetbank.o \
    build/src/libultra/audio/cspsetvol.o \
    build/src/libultra/audio/sndpsetsound.o \
    build/src/libultra/audio/sndpgetstate.o \
    build/src/libultra/audio/sndpsetpitch.o \
    build/src/libultra/audio/sndpsetpan.o \
    build/src/libultra/audio/sndpsetvol.o \
    build/src/libultra/audio/sndpplay.o \
    build/src/libultra/audio/cspstop.o \
    build/src/libultra/audio/cseq.o \
    build/src/libultra/audio/cspsetseq.o \
    build/src/libultra/audio/cspplay.o \
    build/src/libultra/audio/sndpstop.o \
    build/src/libultra/audio/synthesizer.o \
    build/src/libultra/io/aisetnextbuf.o \
    build/src/libultra/gu/sinf.o \
    build/src/libultra/gu/cosf.o \
    build/src/libultra/libc/llcvt.o \
    build/src/libultra/gu/perspective.o \
    build/src/libultra/gu/lookat.o \
    build/src/libultra/gu/lookatref.o \
    build/src/libultra/gu/mtxcatf.o \
    build/asm/libultra/gu/sqrtf.o \
    build/asm/libultra/os/interrupt.o \
    build/src/libultra/io/vi.o \
    build/asm/libultra/os/setsr.o \
    build/asm/libultra/os/getsr.o \
    build/asm/libultra/os/setfpccsr.o \
    build/src/libultra/io/sirawread.o \
    build/src/libultra/io/sirawwrite.o \
    build/asm/libultra/os/exceptasm.o \
    build/asm/libultra/os/writebackdcache.o \
    build/asm/libultra/os/invalicache.o \
    build/asm/libultra/os/maptlbrdb.o \
    build/src/libultra/io/pirawread.o \
    build/asm/libultra/libc/bzero.o \
    build/src/libultra/os/thread.o \
    build/src/libultra/io/cartrominit.o \
    build/src/libultra/io/leodiskinit.o \
    build/src/libultra/io/piacs.o \
    build/src/libultra/os/getthreadpri.o \
    build/src/libultra/io/pirawdma.o \
    build/src/libultra/io/epirawdma.o \
    build/src/libultra/io/devmgr.o \
    build/src/libultra/os/jammesg.o \
    build/src/libultra/io/pigetcmdq.o \
    build/asm/libultra/os/getcount.o \
    build/src/libultra/os/timerintr.o \
    build/src/libultra/io/vigetcurrcontext.o \
    build/src/libultra/io/viswapcontext.o \
    build/src/libultra/io/spgetstat.o \
    build/asm/libultra/libc/bcopy.o \
    build/src/libultra/io/spsetstat.o \
    build/src/libultra/io/spsetpc.o \
    build/src/libultra/io/sprawdma.o \
    build/src/libultra/io/sp.o \
    build/src/libultra/io/dp.o \
    build/src/libultra/io/siacs.o \
    build/src/libultra/io/sirawdma.o \
    build/src/libultra/os/settimer.o \
    build/src/libultra/io/pfsgetstatus.o \
    build/src/libultra/io/contpfs.o \
    build/src/libultra/io/contramread.o \
    build/src/libultra/io/pfschecker.o \
    build/src/libultra/io/pfsisplug.o \
    build/src/libultra/io/crc.o \
    build/src/libultra/io/contramwrite.o \
    build/src/libultra/gu/mtxutil.o \
    build/src/libultra/libc/xprintf.o \
    build/src/libultra/gu/normalize.o \
    build/asm/libultra/os/probetlb.o \
    build/src/libultra/audio/syndelete.o \
    build/src/libultra/audio/event.o \
    build/src/libultra/audio/synaddplayer.o \
    build/src/libultra/audio/synallocvoice.o \
    build/src/libultra/audio/synstartvoice.o \
    build/src/libultra/audio/synsetpan.o \
    build/src/libultra/audio/synsetvol.o \
    build/src/libultra/audio/synsetpitch.o \
    build/src/libultra/audio/synsetfxmix.o \
    build/src/libultra/audio/synstopvoice.o \
    build/src/libultra/audio/synfreevoice.o \
    build/src/libultra/audio/seqplayer.o \
    build/src/libultra/audio/cents2ratio.o \
    build/src/libultra/audio/synstartvoiceparam.o \
    build/src/libultra/audio/drvrNew.o \
    build/src/libultra/audio/synallocfx.o \
    build/src/libultra/audio/mainbus.o \
    build/src/libultra/audio/load.o \
    build/src/libultra/audio/resample.o \
    build/src/libultra/audio/env.o \
    build/src/libultra/audio/auxbus.o \
    build/src/libultra/audio/save.o \
    build/src/libultra/io/ai.o \
    build/src/libultra/io/si.o \
    build/src/libultra/os/kdebugserver.o \
    build/src/libultra/io/leointerrupt.o \
    build/src/libultra/os/destroythread.o \
    build/src/libultra/os/resetglobalintmask.o \
    build/src/libultra/io/epirawwrite.o \
    build/src/libultra/io/epirawread.o \
    build/src/libultra/os/setglobalintmask.o \
    build/asm/libultra/os/setcompare.o \
    build/asm/libultra/os/invaldcache.o \
    build/src/libultra/io/vimodepallan1.o \
    build/src/libultra/io/vimodempallan1.o \
    build/src/libultra/io/vimodentsclan1.o \
    build/src/libultra/libc/xlitob.o \
    build/src/libultra/libc/xldtob.o \
    build/src/libultra/audio/copy.o \
    build/src/libultra/audio/seq.o \
    build/src/libultra/audio/synsetpriority.o \
    build/src/libultra/audio/filter.o \
    build/src/libultra/audio/reverb.o \
    build/src/libultra/libc/ldiv.o \
    build/data/ucode/boot.o \
    build/data/ucode/rdp.o \
    build/data/ucode/asp.o \
    build/data/asm/control.data.o \
    build/data/asm/game1.data.o \
    build/data/asm/control2.data.o \
    build/data/asm/game2.data.o \
    build/data/asm/logo.data.o \
    build/data/asm/boss2.data.o \
    build/data/asm/sound1.data.o \
    build/data/asm/sound2.data.o \
    build/data/src/rend1.data.o \
    build/data/asm/rend2.data.o \
    build/data/asm/menues.data.o \
    build/data/asm/global.data.o \
    build/data/asm/libultra/os/exceptasm.data.o \
    build/data/asm/control.rodata.o \
    build/data/asm/game1.rodata.o \
    build/data/asm/control2.rodata.o \
    build/data/asm/game2.rodata.o \
    build/data/asm/logo.rodata.o \
    build/data/asm/boss2.rodata.o \
    build/data/asm/sound1.rodata.o \
    build/data/asm/rend2.rodata.o \
    build/data/asm/menues.rodata.o \
    build/data/asm/libultra/os/setintmask.rodata.o \
    build/data/asm/libultra/os/exceptasm.rodata.o \
    build/data/asm/libultra/gu/libm_vals.rodata.o \
    build/data/ucode/rdp_data.o \
    build/data/ucode/asp_data.o \
    build/data/asm/control.bss.o \
    build/data/asm/game1.bss.o \
    build/data/asm/control2.bss.o \
    build/data/asm/game2.bss.o \
    build/data/asm/boss2.bss.o \
    build/data/asm/sound1.bss.o \
    build/data/src/rend1.bss.o \
    build/data/asm/rend2.bss.o \
    build/data/asm/menues.bss.o \
    build/data/asm/global.bss.o \
    build/data/asm/global2.bss.o \
    build/assets/palette.o \
    build/src/dlstatic.o \
    build/assets/tileblob.o \
    build/assets/board01.o \
    build/assets/board02.o \
    build/assets/board03.o \
    build/assets/board04.o \
    build/assets/board06.o \
    build/assets/board05.o \
    build/assets/board07.o \
    build/assets/board09.o \
    build/assets/board10.o \
    build/assets/board11.o \
    build/assets/board12.o \
    build/assets/board13.o \
    build/assets/board14.o \
    build/assets/board15.o \
    build/assets/board16.o \
    build/assets/board17.o \
    build/assets/board18.o \
    build/assets/board19.o \
    build/assets/board20.o \
    build/assets/board21.o \
    build/assets/board22.o \
    build/assets/board23.o \
    build/assets/board24.o \
    build/assets/board25.o \
    build/assets/board26.o \
    build/assets/board27.o \
    build/assets/board28.o \
    build/assets/board30.o \
    build/assets/board08.o \
    build/assets/board29.o \
    build/assets/board31.o \
    build/assets/board32.o \
    build/assets/board33.o \
    build/assets/board34.o \
    build/assets/soundctl.o \
    build/assets/soundtbl.o \
    build/assets/musicseq.o \
    build/assets/musicctl.o \
    build/assets/musictbl.o
build/header.o:
build/assets/boot.o:
build/src/entry.o:
build/src/main.o:
build/src/sched.o:
build/asm/control.o:
build/asm/game1.o:
build/asm/control2.o:
build/asm/game2.o:
build/asm/logo.o:
build/asm/boss2.o:
build/asm/sound1.o:
build/asm/sound2.o:
build/src/rend1.o:
build/asm/rend2.o:
build/src/getangle.o:
build/src/draw.o:
build/src/tileinfo.o:
build/src/rnc.o:
build/src/display1.o:
build/src/cache1d.o:
build/src/display2.o:
build/src/actors1.o:
build/src/actors2.o:
build/src/actors3.o:
build/src/gamedef.o:
build/src/script.o:
build/src/engine.o:
build/src/game3.o:
build/src/game4.o:
build/src/player1.o:
build/src/player2.o:
build/src/player3.o:
build/src/premap.o:
build/src/sector.o:
build/src/board.o:
build/src/tile.o:
build/src/tables.o:
build/src/dukebot.o:
build/asm/menues.o:
build/src/libultra/io/viblack.o:
build/src/libultra/os/initialize.o:
build/src/libultra/os/createthread.o:
build/src/libultra/os/startthread.o:
build/src/libultra/io/pimgr.o:
build/src/libultra/os/setthreadpri.o:
build/asm/libultra/os/writebackdcacheall.o:
build/src/libultra/io/pigetstat.o:
build/src/libultra/io/pidma.o:
build/src/libultra/os/recvmesg.o:
build/src/libultra/os/gettime.o:
build/src/libultra/os/sendmesg.o:
build/src/libultra/os/createmesgqueue.o:
build/src/libultra/libc/ll.o:
build/src/libultra/io/visetyscale.o:
build/src/libultra/io/vimgr.o:
build/src/libultra/io/vitbl.o:
build/asm/libultra/unk1.o:
build/src/libultra/io/visetmode.o:
build/src/libultra/io/visetspecial.o:
build/src/libultra/os/seteventmesg.o:
build/src/libultra/io/visetevent.o:
build/asm/libultra/os/setintmask.o:
build/src/libultra/io/sptaskyielded.o:
build/src/libultra/io/vigetcurrframebuf.o:
build/src/libultra/io/vigetnextframebuf.o:
build/src/libultra/io/viswapbuf.o:
build/src/libultra/io/sptask.o:
build/src/libultra/io/dpsetnextbuf.o:
build/src/libultra/io/sptaskyield.o:
build/src/libultra/io/contreaddata.o:
build/src/libultra/io/controller.o:
build/src/libultra/io/pfsinitpak.o:
build/src/libultra/io/pfsnumfiles.o:
build/src/libultra/io/pfsfreeblocks.o:
build/src/libultra/io/motor.o:
build/src/libultra/gu/translate.o:
build/src/libultra/gu/scale.o:
build/src/libultra/libc/sprintf.o:
build/src/libultra/libc/string.o:
build/src/libultra/io/pfsfilestate.o:
build/src/libultra/os/yieldthread.o:
build/src/libultra/io/pfsdeletefile.o:
build/src/libultra/io/pfsallocatefile.o:
build/src/libultra/io/pfsreadwritefile.o:
build/src/libultra/io/pfssearchfile.o:
build/src/libultra/io/pfsrepairid.o:
build/src/libultra/gu/rotate.o:
build/src/libultra/os/virtualtophysical.o:
build/src/libultra/audio/sl.o:
build/src/libultra/audio/heapalloc.o:
build/src/libultra/audio/heapinit.o:
build/src/libultra/io/aisetfreq.o:
build/src/libultra/audio/sndplayer.o:
build/src/libultra/audio/bnkf.o:
build/src/libultra/audio/sndpallocate.o:
build/src/libultra/audio/csplayer.o:
build/src/libultra/audio/seqpsetbank.o:
build/src/libultra/audio/cspsetvol.o:
build/src/libultra/audio/sndpsetsound.o:
build/src/libultra/audio/sndpgetstate.o:
build/src/libultra/audio/sndpsetpitch.o:
build/src/libultra/audio/sndpsetpan.o:
build/src/libultra/audio/sndpsetvol.o:
build/src/libultra/audio/sndpplay.o:
build/src/libultra/audio/cspstop.o:
build/src/libultra/audio/cseq.o:
build/src/libultra/audio/cspsetseq.o:
build/src/libultra/audio/cspplay.o:
build/src/libultra/audio/sndpstop.o:
build/src/libultra/audio/synthesizer.o:
build/src/libultra/io/aisetnextbuf.o:
build/src/libultra/gu/sinf.o:
build/src/libultra/gu/cosf.o:
build/src/libultra/libc/llcvt.o:
build/src/libultra/gu/perspective.o:
build/src/libultra/gu/lookat.o:
build/src/libultra/gu/lookatref.o:
build/src/libultra/gu/mtxcatf.o:
build/asm/libultra/gu/sqrtf.o:
build/asm/libultra/os/interrupt.o:
build/src/libultra/io/vi.o:
build/asm/libultra/os/setsr.o:
build/asm/libultra/os/getsr.o:
build/asm/libultra/os/setfpccsr.o:
build/src/libultra/io/sirawread.o:
build/src/libultra/io/sirawwrite.o:
build/asm/libultra/os/exceptasm.o:
build/asm/libultra/os/writebackdcache.o:
build/asm/libultra/os/invalicache.o:
build/asm/libultra/os/maptlbrdb.o:
build/src/libultra/io/pirawread.o:
build/asm/libultra/libc/bzero.o:
build/src/libultra/os/thread.o:
build/src/libultra/io/cartrominit.o:
build/src/libultra/io/leodiskinit.o:
build/src/libultra/io/piacs.o:
build/src/libultra/os/getthreadpri.o:
build/src/libultra/io/pirawdma.o:
build/src/libultra/io/epirawdma.o:
build/src/libultra/io/devmgr.o:
build/src/libultra/os/jammesg.o:
build/src/libultra/io/pigetcmdq.o:
build/asm/libultra/os/getcount.o:
build/src/libultra/os/timerintr.o:
build/src/libultra/io/vigetcurrcontext.o:
build/src/libultra/io/viswapcontext.o:
build/src/libultra/io/spgetstat.o:
build/asm/libultra/libc/bcopy.o:
build/src/libultra/io/spsetstat.o:
build/src/libultra/io/spsetpc.o:
build/src/libultra/io/sprawdma.o:
build/src/libultra/io/sp.o:
build/src/libultra/io/dp.o:
build/src/libultra/io/siacs.o:
build/src/libultra/io/sirawdma.o:
build/src/libultra/os/settimer.o:
build/src/libultra/io/pfsgetstatus.o:
build/src/libultra/io/contpfs.o:
build/src/libultra/io/contramread.o:
build/src/libultra/io/pfschecker.o:
build/src/libultra/io/pfsisplug.o:
build/src/libultra/io/crc.o:
build/src/libultra/io/contramwrite.o:
build/src/libultra/gu/mtxutil.o:
build/src/libultra/libc/xprintf.o:
build/src/libultra/gu/normalize.o:
build/asm/libultra/os/probetlb.o:
build/src/libultra/audio/syndelete.o:
build/src/libultra/audio/event.o:
build/src/libultra/audio/synaddplayer.o:
build/src/libultra/audio/synallocvoice.o:
build/src/libultra/audio/synstartvoice.o:
build/src/libultra/audio/synsetpan.o:
build/src/libultra/audio/synsetvol.o:
build/src/libultra/audio/synsetpitch.o:
build/src/libultra/audio/synsetfxmix.o:
build/src/libultra/audio/synstopvoice.o:
build/src/libultra/audio/synfreevoice.o:
build/src/libultra/audio/seqplayer.o:
build/src/libultra/audio/cents2ratio.o:
build/src/libultra/audio/synstartvoiceparam.o:
build/src/libultra/audio/drvrNew.o:
build/src/libultra/audio/synallocfx.o:
build/src/libultra/audio/mainbus.o:
build/src/libultra/audio/load.o:
build/src/libultra/audio/resample.o:
build/src/libultra/audio/env.o:
build/src/libultra/audio/auxbus.o:
build/src/libultra/audio/save.o:
build/src/libultra/io/ai.o:
build/src/libultra/io/si.o:
build/src/libultra/os/kdebugserver.o:
build/src/libultra/io/leointerrupt.o:
build/src/libultra/os/destroythread.o:
build/src/libultra/os/resetglobalintmask.o:
build/src/libultra/io/epirawwrite.o:
build/src/libultra/io/epirawread.o:
build/src/libultra/os/setglobalintmask.o:
build/asm/libultra/os/setcompare.o:
build/asm/libultra/os/invaldcache.o:
build/src/libultra/io/vimodepallan1.o:
build/src/libultra/io/vimodempallan1.o:
build/src/libultra/io/vimodentsclan1.o:
build/src/libultra/libc/xlitob.o:
build/src/libultra/libc/xldtob.o:
build/src/libultra/audio/copy.o:
build/src/libultra/audio/seq.o:
build/src/libultra/audio/synsetpriority.o:
build/src/libultra/audio/filter.o:
build/src/libultra/audio/reverb.o:
build/src/libultra/libc/ldiv.o:
build/data/ucode/boot.o:
build/data/ucode/rdp.o:
build/data/ucode/asp.o:
build/data/asm/control.data.o:
build/data/asm/game1.data.o:
build/data/asm/control2.data.o:
build/data/asm/game2.data.o:
build/data/asm/logo.data.o:
build/data/asm/boss2.data.o:
build/data/asm/sound1.data.o:
build/data/asm/sound2.data.o:
build/data/src/rend1.data.o:
build/data/asm/rend2.data.o:
build/data/asm/menues.data.o:
build/data/asm/global.data.o:
build/data/asm/libultra/os/exceptasm.data.o:
build/data/asm/control.rodata.o:
build/data/asm/game1.rodata.o:
build/data/asm/control2.rodata.o:
build/data/asm/game2.rodata.o:
build/data/asm/logo.rodata.o:
build/data/asm/boss2.rodata.o:
build/data/asm/sound1.rodata.o:
build/data/asm/rend2.rodata.o:
build/data/asm/menues.rodata.o:
build/data/asm/libultra/os/setintmask.rodata.o:
build/data/asm/libultra/os/exceptasm.rodata.o:
build/data/asm/libultra/gu/libm_vals.rodata.o:
build/data/ucode/rdp_data.o:
build/data/ucode/asp_data.o:
build/data/asm/control.bss.o:
build/data/asm/game1.bss.o:
build/data/asm/control2.bss.o:
build/data/asm/game2.bss.o:
build/data/asm/boss2.bss.o:
build/data/asm/sound1.bss.o:
build/data/src/rend1.bss.o:
build/data/asm/rend2.bss.o:
build/data/asm/menues.bss.o:
build/data/asm/global.bss.o:
build/data/asm/global2.bss.o:
build/assets/palette.o:
build/src/dlstatic.o:
build/assets/tileblob.o:
build/assets/board01.o:
build/assets/board02.o:
build/assets/board03.o:
build/assets/board04.o:
build/assets/board06.o:
build/assets/board05.o:
build/assets/board07.o:
build/assets/board09.o:
build/assets/board10.o:
build/assets/board11.o:
build/assets/board12.o:
build/assets/board13.o:
build/assets/board14.o:
build/assets/board15.o:
build/assets/board16.o:
build/assets/board17.o:
build/assets/board18.o:
build/assets/board19.o:
build/assets/board20.o:
build/assets/board21.o:
build/assets/board22.o:
build/assets/board23.o:
build/assets/board24.o:
build/assets/board25.o:
build/assets/board26.o:
build/assets/board27.o:
build/assets/board28.o:
build/assets/board30.o:
build/assets/board08.o:
build/assets/board29.o:
build/assets/board31.o:
build/assets/board32.o:
build/assets/board33.o:
build/assets/board34.o:
build/assets/soundctl.o:
build/assets/soundtbl.o:
build/assets/musicseq.o:
build/assets/musicctl.o:
build/assets/musictbl.o:
-include build/header.d build/assets/boot.d build/src/entry.d build/src/main.d build/src/sched.d build/asm/control.d build/asm/game1.d build/asm/control2.d build/asm/game2.d build/asm/logo.d build/asm/boss2.d build/asm/sound1.d build/asm/sound2.d build/src/rend1.d build/asm/rend2.d build/src/getangle.d build/src/draw.d build/src/tileinfo.d build/src/rnc.d build/src/display1.d build/src/cache1d.d build/src/display2.d build/src/actors1.d build/src/actors2.d build/src/actors3.d build/src/gamedef.d build/src/script.d build/src/engine.d build/src/game3.d build/src/game4.d build/src/player1.d build/src/player2.d build/src/player3.d build/src/premap.d build/src/sector.d build/src/board.d build/src/tile.d build/src/tables.d build/src/dukebot.d build/asm/menues.d build/src/libultra/io/viblack.d build/src/libultra/os/initialize.d build/src/libultra/os/createthread.d build/src/libultra/os/startthread.d build/src/libultra/io/pimgr.d build/src/libultra/os/setthreadpri.d build/asm/libultra/os/writebackdcacheall.d build/src/libultra/io/pigetstat.d build/src/libultra/io/pidma.d build/src/libultra/os/recvmesg.d build/src/libultra/os/gettime.d build/src/libultra/os/sendmesg.d build/src/libultra/os/createmesgqueue.d build/src/libultra/libc/ll.d build/src/libultra/io/visetyscale.d build/src/libultra/io/vimgr.d build/src/libultra/io/vitbl.d build/asm/libultra/unk1.d build/src/libultra/io/visetmode.d build/src/libultra/io/visetspecial.d build/src/libultra/os/seteventmesg.d build/src/libultra/io/visetevent.d build/asm/libultra/os/setintmask.d build/src/libultra/io/sptaskyielded.d build/src/libultra/io/vigetcurrframebuf.d build/src/libultra/io/vigetnextframebuf.d build/src/libultra/io/viswapbuf.d build/src/libultra/io/sptask.d build/src/libultra/io/dpsetnextbuf.d build/src/libultra/io/sptaskyield.d build/src/libultra/io/contreaddata.d build/src/libultra/io/controller.d build/src/libultra/io/pfsinitpak.d build/src/libultra/io/pfsnumfiles.d build/src/libultra/io/pfsfreeblocks.d build/src/libultra/io/motor.d build/src/libultra/gu/translate.d build/src/libultra/gu/scale.d build/src/libultra/libc/sprintf.d build/src/libultra/libc/string.d build/src/libultra/io/pfsfilestate.d build/src/libultra/os/yieldthread.d build/src/libultra/io/pfsdeletefile.d build/src/libultra/io/pfsallocatefile.d build/src/libultra/io/pfsreadwritefile.d build/src/libultra/io/pfssearchfile.d build/src/libultra/io/pfsrepairid.d build/src/libultra/gu/rotate.d build/src/libultra/os/virtualtophysical.d build/src/libultra/audio/sl.d build/src/libultra/audio/heapalloc.d build/src/libultra/audio/heapinit.d build/src/libultra/io/aisetfreq.d build/src/libultra/audio/sndplayer.d build/src/libultra/audio/bnkf.d build/src/libultra/audio/sndpallocate.d build/src/libultra/audio/csplayer.d build/src/libultra/audio/seqpsetbank.d build/src/libultra/audio/cspsetvol.d build/src/libultra/audio/sndpsetsound.d build/src/libultra/audio/sndpgetstate.d build/src/libultra/audio/sndpsetpitch.d build/src/libultra/audio/sndpsetpan.d build/src/libultra/audio/sndpsetvol.d build/src/libultra/audio/sndpplay.d build/src/libultra/audio/cspstop.d build/src/libultra/audio/cseq.d build/src/libultra/audio/cspsetseq.d build/src/libultra/audio/cspplay.d build/src/libultra/audio/sndpstop.d build/src/libultra/audio/synthesizer.d build/src/libultra/io/aisetnextbuf.d build/src/libultra/gu/sinf.d build/src/libultra/gu/cosf.d build/src/libultra/libc/llcvt.d build/src/libultra/gu/perspective.d build/src/libultra/gu/lookat.d build/src/libultra/gu/lookatref.d build/src/libultra/gu/mtxcatf.d build/asm/libultra/gu/sqrtf.d build/asm/libultra/os/interrupt.d build/src/libultra/io/vi.d build/asm/libultra/os/setsr.d build/asm/libultra/os/getsr.d build/asm/libultra/os/setfpccsr.d build/src/libultra/io/sirawread.d build/src/libultra/io/sirawwrite.d build/asm/libultra/os/exceptasm.d build/asm/libultra/os/writebackdcache.d build/asm/libultra/os/invalicache.d build/asm/libultra/os/maptlbrdb.d build/src/libultra/io/pirawread.d build/asm/libultra/libc/bzero.d build/src/libultra/os/thread.d build/src/libultra/io/cartrominit.d build/src/libultra/io/leodiskinit.d build/src/libultra/io/piacs.d build/src/libultra/os/getthreadpri.d build/src/libultra/io/pirawdma.d build/src/libultra/io/epirawdma.d build/src/libultra/io/devmgr.d build/src/libultra/os/jammesg.d build/src/libultra/io/pigetcmdq.d build/asm/libultra/os/getcount.d build/src/libultra/os/timerintr.d build/src/libultra/io/vigetcurrcontext.d build/src/libultra/io/viswapcontext.d build/src/libultra/io/spgetstat.d build/asm/libultra/libc/bcopy.d build/src/libultra/io/spsetstat.d build/src/libultra/io/spsetpc.d build/src/libultra/io/sprawdma.d build/src/libultra/io/sp.d build/src/libultra/io/dp.d build/src/libultra/io/siacs.d build/src/libultra/io/sirawdma.d build/src/libultra/os/settimer.d build/src/libultra/io/pfsgetstatus.d build/src/libultra/io/contpfs.d build/src/libultra/io/contramread.d build/src/libultra/io/pfschecker.d build/src/libultra/io/pfsisplug.d build/src/libultra/io/crc.d build/src/libultra/io/contramwrite.d build/src/libultra/gu/mtxutil.d build/src/libultra/libc/xprintf.d build/src/libultra/gu/normalize.d build/asm/libultra/os/probetlb.d build/src/libultra/audio/syndelete.d build/src/libultra/audio/event.d build/src/libultra/audio/synaddplayer.d build/src/libultra/audio/synallocvoice.d build/src/libultra/audio/synstartvoice.d build/src/libultra/audio/synsetpan.d build/src/libultra/audio/synsetvol.d build/src/libultra/audio/synsetpitch.d build/src/libultra/audio/synsetfxmix.d build/src/libultra/audio/synstopvoice.d build/src/libultra/audio/synfreevoice.d build/src/libultra/audio/seqplayer.d build/src/libultra/audio/cents2ratio.d build/src/libultra/audio/synstartvoiceparam.d build/src/libultra/audio/drvrNew.d build/src/libultra/audio/synallocfx.d build/src/libultra/audio/mainbus.d build/src/libultra/audio/load.d build/src/libultra/audio/resample.d build/src/libultra/audio/env.d build/src/libultra/audio/auxbus.d build/src/libultra/audio/save.d build/src/libultra/io/ai.d build/src/libultra/io/si.d build/src/libultra/os/kdebugserver.d build/src/libultra/io/leointerrupt.d build/src/libultra/os/destroythread.d build/src/libultra/os/resetglobalintmask.d build/src/libultra/io/epirawwrite.d build/src/libultra/io/epirawread.d build/src/libultra/os/setglobalintmask.d build/asm/libultra/os/setcompare.d build/asm/libultra/os/invaldcache.d build/src/libultra/io/vimodepallan1.d build/src/libultra/io/vimodempallan1.d build/src/libultra/io/vimodentsclan1.d build/src/libultra/libc/xlitob.d build/src/libultra/libc/xldtob.d build/src/libultra/audio/copy.d build/src/libultra/audio/seq.d build/src/libultra/audio/synsetpriority.d build/src/libultra/audio/filter.d build/src/libultra/audio/reverb.d build/src/libultra/libc/ldiv.d build/data/ucode/boot.d build/data/ucode/rdp.d build/data/ucode/asp.d build/data/asm/control.data.d build/data/asm/game1.data.d build/data/asm/control2.data.d build/data/asm/game2.data.d build/data/asm/logo.data.d build/data/asm/boss2.data.d build/data/asm/sound1.data.d build/data/asm/sound2.data.d build/data/src/rend1.data.d build/data/asm/rend2.data.d build/data/asm/menues.data.d build/data/asm/global.data.d build/data/asm/libultra/os/exceptasm.data.d build/data/asm/control.rodata.d build/data/asm/game1.rodata.d build/data/asm/control2.rodata.d build/data/asm/game2.rodata.d build/data/asm/logo.rodata.d build/data/asm/boss2.rodata.d build/data/asm/sound1.rodata.d build/data/asm/rend2.rodata.d build/data/asm/menues.rodata.d build/data/asm/libultra/os/setintmask.rodata.d build/data/asm/libultra/os/exceptasm.rodata.d build/data/asm/libultra/gu/libm_vals.rodata.d build/data/ucode/rdp_data.d build/data/ucode/asp_data.d build/data/asm/control.bss.d build/data/asm/game1.bss.d build/data/asm/control2.bss.d build/data/asm/game2.bss.d build/data/asm/boss2.bss.d build/data/asm/sound1.bss.d build/data/src/rend1.bss.d build/data/asm/rend2.bss.d build/data/asm/menues.bss.d build/data/asm/global.bss.d build/data/asm/global2.bss.d build/assets/palette.d build/src/dlstatic.d build/assets/tileblob.d build/assets/board01.d build/assets/board02.d build/assets/board03.d build/assets/board04.d build/assets/board06.d build/assets/board05.d build/assets/board07.d build/assets/board09.d build/assets/board10.d build/assets/board11.d build/assets/board12.d build/assets/board13.d build/assets/board14.d build/assets/board15.d build/assets/board16.d build/assets/board17.d build/assets/board18.d build/assets/board19.d build/assets/board20.d build/assets/board21.d build/assets/board22.d build/assets/board23.d build/assets/board24.d build/assets/board25.d build/assets/board26.d build/assets/board27.d build/assets/board28.d build/assets/board30.d build/assets/board08.d build/assets/board29.d build/assets/board31.d build/assets/board32.d build/assets/board33.d build/assets/board34.d build/assets/soundctl.d build/assets/soundtbl.d build/assets/musicseq.d build/assets/musicctl.d build/assets/musictbl.d
