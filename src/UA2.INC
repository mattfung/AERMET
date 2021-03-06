C  UA2.INC
C       WE ANTICIPATE THESE WILL BE USEFUL ONLY DURING
C       PREPROCESSING
C
      INTEGER      DEV10,DEV12,DEV13
      INTEGER      UADCD,UADAY1,UADAY2,UAYR1,UAYR2
      INTEGER      UAGDY1,UAGDY2,UAGMO1,UAGMO2,UAGDY,UAGMO
      INTEGER      UAGYR,UAGHR,UADAYC,UALDY,UALMO,UALYR,UALHR,UALEV
      INTEGER      UAID                                                  ! add UAID for UA subs
      INTEGER      UADAY,UAMO,UAYR,UAHR,UAQA,UAVAUD,
     1              UAAUDT,UATOP,UAINC,UAVTRA,UALST
      CHARACTER*96 UNIT10,DISK12,DISK13
      CHARACTER*8  UALOC1
      CHARACTER*4  UAVAR
      CHARACTER*2  UABLK
C
      COMMON /UABK03/ DEV10,DEV12,DEV13
      COMMON /UABK04/ UNIT10,DISK12,DISK13,UAVAR(UAVR),UABLK,
     1                UALOC1
      COMMON /UABK05/ UADCD,UADAYC,UADAY1,UADAY2,UAYR1,
     1                UAYR2,UAGDY1,UAGDY2,UAGMO1,UAGMO2,UAGDY,UAGMO,
     1                UAGYR,UAGHR,UALDY,UALMO,UALYR,UALHR,UALST,
     1                UAID                                                  ! add UAID for UA subs
      COMMON /UABK06/ UALEV(UAMH),UADAY(UAMH),UAMO(UAMH),UAYR(UAMH),
     1                UAHR(UAMH),UAQA(UAVR,4),UAVAUD(UAVR-2),
     1                UAAUDT(UAVR-2,10,0:3),UATOP,UAINC,UAVTRA(UAVR-2)
C
C       DEV10           DEVICE NUMBER FOR UA SOUNDING DATA
C       DEV12           DEVICE NUMBER FOR UA QA INPUT DATA
C       DEV13           DEVICE NUMBER FOR UA QA OUTPUT DATA
C       UNIT10          FILENAME FOR DEV10
C       DISK12          FILENAME FOR DEV12
C       DISK13          FILENAME FOR DEV13
C       UASKIP          THE NUMBER OF CHARACTERS TO SKIP BETWEEN
C                        UPPER AIR SOUNDINGS WITHIN A BLOCK
C       UADCD           FORMAT CODE FOR DATA ON TAPE
C       UABLK           BLOCKING FORMAT OF DATA ON TAPE ('FB' OR 'VB')
C       UALST           CONVERSION FACTOR FOR USER TIME TO SOLAR TIME,
C                        SUCH THAT USER TIME - FACTOR = SOLAR TIME
C       UADAY1,UADAY2   START, STOP CHRONOLOGICAL DAYS FOR UA EXTRACT
C       UAYR1,UAYR2     START AND STOP YEAR FOR UA EXTRACT DATA
C       UAGDY1,UAGDY2   START AND STOP DAYS (GREGORIAN)
C       UAGMO1,UAGMO2   START AND STOP MONTHS (GREGORIAN)
C       UAGDY...UAGHR   CURRENT SOUNDING DATE BEING
C                       PROCESSED (GREGORIAN)
C       UADAYC          CURRENT CHRONOLOGICAL DAY BEING PROCESSED
C                        (JULIAN DAY IN MERGE)
C       UALDY...UALHR   LAST SOUNDING DATE PROCESSED (GREGORIAN)
C       UALOC1          UPPER AIR STATION ID TO BE PROCESSED
C       UALEV           NUMBER OF LEVELS OF DATA FOR EACH SOUNDING
C       UAID            UPPER AIR STATION ID; USED TO TRACK UA DATA SUBSTITUTIONS
C       UADAY...UAHR    DAY, MONTH, YEAR, HOUR FOR EACH SOUNDING MERGED
C       UAQA            MISSING VALUE, LOWER AND UPPER RANGE CHECK
C                       BOUNDS FOR UA VARIABLES
C                       (TEST METHOD, MISSING VALUE, LOWER BOUND, UPPER
C                        BOUND)
C                       TEST METHOD 1 = EXCLUDING BOUNDS,
C                                   2 = INCLUDING BOUNDS
C                       VARIABLE    1 = PRESSURE (*10)
C                                   2 = HEIGHT (*1)
C                                   3 = TEMPERATURE (*10)
C                                   4 = DEW POINT  (*10)
C                                   5 = WIND DIRECTION (*1)
C                                   6 = WIND SPEED (*10)
C                                   7 = SPEED SHEAR (M/S PER 100 M)
C                                   8 = DIRECTIONAL SHEAR (DEG./100 M)
C                                   9 = LAPSE RATE (DEG. C /100 M)
C                                  10 = DEW PT DEVIATION (DEG. C /10 M)
C                                  11 = A.M. MIXING HT.
C                                  12 = P.M. MIXING HT.
C       UAAUDT(I,L,J)   AUDIT RESULTS FOR VECTOR VARIABLES
C                            1 MISSING COUNTER
C                            2 LOWER BOUND VIOLATION COUNTER
C                            3 UPPER BOUND VIOLATION COUNTER
C                        RESULTS ARE STORED IN TEN HEIGHT INTERVALS.
C                            I = VARIABLE
C                            L = HEIGHT INTERVAL
C                            J = 0 QA GOOD COUNTER
C       UAVAUD(I)       AUDIT INDICATOR FOR THE SOUNDING (VECTOR)
C                        VARIABLES.
C                            0 = NO OUTPUT AUDIT SUMMARY FOR THIS VAR.
C                            1 = OUTPUT AUDIT SUMMARY FOR THIS VAR.
C       UAINC           LAYER THICKNESS (HEIGHT INTERVAL) USED IN
C                        DEVLELOPING UAAUDT AUDIT RESULTS.
C       UATOP           CLIPPING HEIGHT FOR UA SOUNDINGS (NO LEVELS
C                       PROCESSED ABOVE THIS HEIGHT)
C       UAVAR           CHARACTER*4 'NAMES' FOR THE UA VARIABLES THAT
C                       CAN BE RANGE CHECKED.  BASIC USE OF THESE
C                       NAMES IS DURING SETUP WHEN USER WISHES TO
C                       REDEFINE THE RANGE CHECKS.
C       UAVTRA(I)       NO-MISSING INDICATOR FOR (VECTOR) VARIABLES.

