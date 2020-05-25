//
//  Line.h
//  Writer / Beat
//
//  Created by Hendrik Noeller on 01.04.16.
//  Copyright © 2016 Hendrik Noeller. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FNElement.h"

typedef enum : NSUInteger {
    empty = 0,
    section,
    synopse,
    titlePageTitle,
    titlePageAuthor,
    titlePageCredit,
    titlePageSource,
    titlePageContact,
    titlePageDraftDate,
    titlePageUnknown,
    heading,
    action,
    character,
    parenthetical,
    dialogue,
    dualDialogueCharacter,
    dualDialogueParenthetical,
    dualDialogue,
    transitionLine,
    lyrics,
    pageBreak,
    centered,
	more
} LineType;


@interface Line : NSObject

@property LineType type;
@property (strong, nonatomic) NSString* string;
@property NSUInteger position;
@property NSUInteger numberOfPreceedingFormattingCharacters;
@property NSUInteger sectionDepth;
@property NSString* sceneNumber;
@property NSString* color;
//@property double height;

@property NSMutableIndexSet* boldRanges;
@property NSMutableIndexSet* italicRanges;
@property NSMutableIndexSet* underlinedRanges;
@property NSMutableIndexSet* noteRanges;
@property NSMutableIndexSet* omitedRanges;
@property bool omitIn; //wether the line terminates an unfinished omit
@property bool omitOut; //Wether the line starts an omit and doesn't finish it

- (Line*)initWithString:(NSString*)string position:(NSUInteger)position;
- (Line*)initWithString:(NSString*)string type:(LineType)type;
- (Line*)initWithString:(NSString*)string type:(LineType)type position:(NSUInteger)position;
- (NSString*)toString;
- (NSString*)typeAsString;
- (NSString*)typeAsFountainString;
- (NSString*)cleanedString;
- (bool)omited;

+ (Line*)withString:(NSString*)string type:(LineType)type;

// This is a method for converting Line to FNElement
- (FNElement*)fountainElement;

// Note: Following stuff is intended ONLY for non-continuous parsing
- (bool)isTitlePage;
- (bool)isInvisible;
- (bool)isDialogueElement;
@property bool isSplitParagraph;
@property bool nextElementIsDualDialogue; // Note: this is ONLY used for non-continuous parsing


@end
