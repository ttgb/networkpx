/*
 *     Generated by class-dump 3.1.2.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2007 by Steve Nygard.
 */

#import <Foundation/NSObject.h>
#import <UIKit2/CDStructures.h>
#import <GraphicsServices/GSEvent.h>

@class UIKeyboardCandidateList, UIKeyboardLayout, NSArray, NSString;

@interface UIKeyboardInputManager : NSObject {}

+(UIKeyboardInputManager*)sharedInstanceForInputMode:(NSString*)mode;
+(UIKeyboardInputManager*)activeInstance;
+(void)releaseSharedInstance;

// Event handler when "str" is entered.
- (void)addInput:(NSString*)str flags:(NSUInteger)flg point:(struct CGPoint)point;


- (void)setInput:(id)fp8;

// Event handler when delete key is hit.
// You should remove the last character from the input string when this is called.
- (void)deleteFromInput;
- (void)clearInput;

// Accept input instead of autocorrect.
- (void)acceptInput;
@property(assign) NSUInteger inputIndex;

// ?
// Return a nonzero number if you want to show candidates...
@property(assign,readonly) NSUInteger inputCount;

// The current string. It will be highlighted in the text field.
// Useful for IME.
// e.g. CJManager.inputString -> @"一弓一月金"
//      KanaManager.inputString -> @"hatake"	// the user typed "hatake" before confirming the input to form ハタケ
@property(copy,readonly) NSString* inputString;

// The caret (cursor) is moved.
// Called from: -[UIKeyboardImpl textChanged:]
- (void)inputLocationChanged;

// Ask if the specified character ends a word.
// In normal circumstances, ending a word confirms auto-complete.
// You can use helper method -[NSString endsWord] defined in the category UIKBExtras.
// e.g. [myManager stringEndsWord:@","] -> YES (a comma ends a word)
//      [myManager stringEndsWord:@"x"] -> NO  (an alphabet doesn't end a word)
- (BOOL)stringEndsWord:(NSString*)character;


- (id)composedTyping;

// The string to display as Auto-correction.
// Return nil to suppress it.
- (NSString*)autocorrection;

// Return an NSArray of CandWord which contains all possible candidates.
- (NSArray*)candidates;


- (id)remainingInput;
- (BOOL)usesCandidateSelection;
- (BOOL)usesAutoDeleteWord;
- (BOOL)suppressesCandidateDisplay;
- (id)defaultCandidate;

// Returns if candidates should be shown even if nothing was entered.
// Useful for associated phrases in IME.
// e.g. User accepted a Chinese character "你".
//      the program can return YES with [CJManager suppliesCompletions];
//      and return {"們", "好", "和我"} to complete the phrase.
- (BOOL)suppliesCompletions;

// Returns the string to output when "key" is double-clicked.
// e.g. [myManager stringForDoubleKey:@" "] --> @". "
// Called only when space bar is double-clicked. :S
- (NSString*)stringForDoubleKey:(NSString*)key;

- (BOOL)setInputMode:(NSString*)mode;

// Event handler for if autocorrection is enabled from preference & text traits
- (void)setAutoCorrects:(BOOL)fp8;

// Event handler for shift state
- (void)setShift:(BOOL)fp8;

// Event handler for a change in state of auto-shift.
- (void)setAutoShift:(BOOL)fp8;

// If return YES, when the caret is in part of a word and something was entered,
// that word will be sent to -setInput: first.
// e.g. putting the caret in the middle of the string "abcde" will call
//      [myManager setInput:@"abcde"];
- (BOOL)shouldExtendPriorWord;

// Configure the keyboard layout for the candidate list.
// Applied for default CJK IMEs, if there are multiple candidates, the "Enter" key
//  will show "Dismiss" and tapping it will call -[UIKeyboardImpl clearInput].
- (void)configureKeyboard:(UIKeyboardLayout*)layout forCandidates:(UIKeyboardCandidateList*)candidates;


- (void)addToTypingHistory:(id)fp8;

// Event handler for that the text "str" accepted.
- (void)textAccepted:(NSString*)str;

// Event handler for that a candidate word is accepted.
- (void)candidateAccepted:(id)candword;

// Event handlers for that a string "str" will have its frequency changed.
- (void)increaseUserFrequency:(NSString*)str;
- (void)decreaseUserFrequency:(NSString*)str;


- (void)clearDynamicDictionary;
- (void)loadAddressBook;
- (id)shadowTyping;
- (void)setCalculatesChargedKeyProbabilities:(BOOL)fp8;
- (struct __CFArray *)chargeableKeys;
- (struct __CFDictionary *)chargedKeyProbabilities;

// The user hit key.
// e.g. [myManager addInputObject:@"h"] is called == the "H" key is hit.
- (NSString*)addInputObject:(NSString*)obj;
- (NSString*)setInputObject:(NSString*)obj;

- (BOOL)canHandleKeyHitTest;
- (void)clearKeyAreas;
- (void)registerKeyArea:(struct CGPoint)fp8 withRadii:(struct CGPoint)fp16 forKeyCode:(unsigned short)fp24 forLowerKey:(id)fp28 forUpperKey:(id)fp32;
- (int)keyHitTest:(struct CGPoint)fp8 touchStage:(int)fp16 atTime:(double)fp20 withPathInfo:(GSPathInfo*)fp28 forceShift:(BOOL)fp32;
- (BOOL)keySlidIntoSwipe;
- (int)keyCancel:(struct CGPoint)fp8 atTime:(double)fp16 fromPath:(int)fp24 withIdentity:(int)fp28 forceShift:(BOOL)fp32;
- (void)deleteFromStrokeHistory:(BOOL)fp8;

@end
