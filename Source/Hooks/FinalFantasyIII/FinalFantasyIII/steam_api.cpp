#include "ml.h"

#define STEAM_API_NODLL 1
#pragma warning(disable:4819)

#include "steam\steam_api.h"
#include "steam\steam_gameserver.h"

using ml::String;

#if 0
    #define STEAM_LOG(...) (PrintConsole(L"[%S] ", __FUNCTION__), PrintConsole(__VA_ARGS__), PrintConsole(L"\n"))
#else
    #define STEAM_LOG(...)
#endif

#define S_VIRTUAL THISCALL

struct CSteamApps : public ISteamApps
{
public:
    virtual bool S_VIRTUAL BIsSubscribed()
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual bool S_VIRTUAL BIsLowViolence()
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual bool S_VIRTUAL BIsCybercafe()
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual bool S_VIRTUAL BIsVACBanned()
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual PCSTR S_VIRTUAL GetCurrentGameLanguage()
    {
        STEAM_LOG(L"");
        return "jp";
    }

    virtual PCSTR S_VIRTUAL GetAvailableGameLanguages()
    {
        STEAM_LOG(L"");
        return "jp";
    }

    virtual bool S_VIRTUAL BIsSubscribedApp(AppId_t appID)
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual bool S_VIRTUAL BIsDlcInstalled(AppId_t appID)
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual uint32 S_VIRTUAL GetEarliestPurchaseUnixTime(AppId_t nAppID)
    {
        STEAM_LOG(L"");
        return 0;
    }

    virtual bool S_VIRTUAL BIsSubscribedFromFreeWeekend()
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual int S_VIRTUAL GetDLCCount()
    {
        STEAM_LOG(L"");
        return 0;
    }

    virtual bool S_VIRTUAL BGetDLCDataByIndex( int iDLC, AppId_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize )
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual void S_VIRTUAL InstallDLC( AppId_t nAppID )
    {
        STEAM_LOG(L"");
    }

    virtual void S_VIRTUAL UninstallDLC( AppId_t nAppID )
    {
        STEAM_LOG(L"");
    }

    virtual void S_VIRTUAL RequestAppProofOfPurchaseKey(AppId_t nAppID)
    {
        STEAM_LOG(L"");
    }

    virtual bool S_VIRTUAL GetCurrentBetaName( char *pchName, int cchNameBufferSize )
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual bool S_VIRTUAL MarkContentCorrupt( bool bMissingFilesOnly )
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual uint32 S_VIRTUAL GetInstalledDepots( AppId_t appID, DepotId_t *pvecDepots, uint32 cMaxDepots )
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual uint32 S_VIRTUAL GetAppInstallDir( AppId_t appID, char *pchFolder, uint32 cchFolderBufferSize )
    {
        STEAM_LOG(L"");
        return 0;
    }

    virtual bool S_VIRTUAL BIsAppInstalled(AppId_t appID)
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual CSteamID S_VIRTUAL GetAppOwner()
    {
        STEAM_LOG(L"");
        return CSteamID();
    }

    virtual PCSTR S_VIRTUAL GetLaunchQueryParam(PCSTR pchKey)
    {
        STEAM_LOG(L"");
        return "";
    }

    virtual bool GetDlcDownloadProgress(AppId_t nAppID, uint64 *punBytesDownloaded, uint64 *punBytesTotal)
    {
        if (punBytesDownloaded != nullptr)
            *punBytesDownloaded = 1;

        if (punBytesTotal != nullptr)
            *punBytesTotal = 1;

        return true;
    }

    virtual int GetAppBuildId()
    {
        return 0;
    }

#ifdef _PS3
    // Result returned in a RegisterActivationCodeResponse_t callresult
    virtual SteamAPICall_t RegisterActivationCode(const char *pchActivationCode)
    {
        return k_uAPICallInvalid;
    }
#endif
};

struct CSteamClient : public ISteamClient
{
public:
    virtual HSteamPipe S_VIRTUAL CreateSteamPipe()
    {
        STEAM_LOG(L"");
        return 0;
    }

    virtual bool S_VIRTUAL BReleaseSteamPipe(HSteamPipe steamPipe)
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual HSteamUser S_VIRTUAL ConnectToGlobalUser(HSteamPipe steamPipe)
    {
        STEAM_LOG(L"");
        return 0;
    }

    virtual HSteamUser S_VIRTUAL CreateLocalUser(HSteamPipe *steamPipe, EAccountType accountType)
    {
        STEAM_LOG(L"");
        return 0;
    }

    virtual void S_VIRTUAL ReleaseUser(HSteamPipe steamPipe, HSteamUser user)
    {
        STEAM_LOG(L"");
    }

    virtual ISteamUser* S_VIRTUAL GetISteamUser(HSteamUser steamUser, HSteamPipe steamPipe, PCSTR version)
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual ISteamGameServer *S_VIRTUAL GetISteamGameServer(HSteamUser steamUser, HSteamPipe steamPipe, PCSTR version)
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual void S_VIRTUAL SetLocalIPBinding(uint32 ip, USHORT port)
    {
        STEAM_LOG(L"");
    }

    virtual ISteamFriends *S_VIRTUAL GetISteamFriends(HSteamUser steamUser, HSteamPipe steamPipe, PCSTR version)
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual ISteamUtils *S_VIRTUAL GetISteamUtils(HSteamPipe steamPipe, PCSTR version)
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual ISteamMatchmaking *S_VIRTUAL GetISteamMatchmaking(HSteamUser steamUser, HSteamPipe steamPipe, PCSTR version)
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual ISteamMatchmakingServers *S_VIRTUAL GetISteamMatchmakingServers(HSteamUser steamUser, HSteamPipe steamPipe, PCSTR version)
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual void *S_VIRTUAL GetISteamGenericInterface(HSteamUser steamUser, HSteamPipe steamPipe, PCSTR version)
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual ISteamUserStats* S_VIRTUAL GetISteamUserStats(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion)
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual ISteamGameServerStats *S_VIRTUAL GetISteamGameServerStats(HSteamUser steamUser, HSteamPipe steamPipe, PCSTR version)
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual ISteamApps *S_VIRTUAL GetISteamApps(HSteamUser steamUser, HSteamPipe steamPipe, PCSTR version)
    {
        STEAM_LOG(L"");
        return SteamApps();
    }

    virtual ISteamNetworking *S_VIRTUAL GetISteamNetworking(HSteamUser steamUser, HSteamPipe steamPipe, PCSTR version)
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual ISteamRemoteStorage *S_VIRTUAL GetISteamRemoteStorage(HSteamUser steamUser, HSteamPipe steamPipe, PCSTR version)
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual ISteamScreenshots *GetISteamScreenshots(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion)
    {
        return nullptr;
    }

    virtual void S_VIRTUAL RunFrame()
    {
        STEAM_LOG(L"");
    }

    virtual uint32 S_VIRTUAL GetIPCCallCount()
    {
        STEAM_LOG(L"");
        return 0;
    }

    virtual void S_VIRTUAL SetWarningMessageHook(SteamAPIWarningMessageHook_t function)
    {
        STEAM_LOG(L"");
    }

    virtual bool S_VIRTUAL BShutdownIfAllPipesClosed()
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual class ISteamHTTP * S_VIRTUAL GetISteamHTTP( HSteamUser hSteamuser, HSteamPipe hSteamPipe, PCSTR pchVersion )
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual class ISteamUnifiedMessages * S_VIRTUAL GetISteamUnifiedMessages( HSteamUser hSteamuser, HSteamPipe hSteamPipe, PCSTR pchVersion )
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual class  ISteamController * S_VIRTUAL GetISteamController( HSteamUser hSteamUser, HSteamPipe hSteamPipe, PCSTR pchVersion )
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual class ISteamUGC * S_VIRTUAL GetISteamUGC( HSteamUser hSteamUser, HSteamPipe hSteamPipe, PCSTR pchVersion )
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual class ISteamAppList * S_VIRTUAL GetISteamAppList( HSteamUser hSteamUser, HSteamPipe hSteamPipe, PCSTR pchVersion )
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual class ISteamMusic * S_VIRTUAL GetISteamMusic( HSteamUser hSteamuser, HSteamPipe hSteamPipe, PCSTR pchVersion )
    {
        STEAM_LOG(L"");
        DebugBreakPoint();
        return nullptr;
    }

    virtual ISteamMusicRemote *GetISteamMusicRemote(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion)
    {
        STEAM_LOG(L"");
        return nullptr;
    }

    virtual ISteamHTMLSurface *GetISteamHTMLSurface(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion)
    {
        STEAM_LOG(L"");
        return nullptr;
    }

    virtual void Set_SteamAPI_CPostAPIResultInProcess(SteamAPI_PostAPIResultInProcess_t func)
    {
        STEAM_LOG(L"");
    }

    virtual void Remove_SteamAPI_CPostAPIResultInProcess(SteamAPI_PostAPIResultInProcess_t func)
    {
        STEAM_LOG(L"");
    }

    virtual void Set_SteamAPI_CCheckCallbackRegisteredInProcess(SteamAPI_CheckCallbackRegistered_t func)
    {
        STEAM_LOG(L"");
    }

    virtual ISteamInventory *GetISteamInventory(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion)
    {
        STEAM_LOG(L"");
        return nullptr;
    }

    virtual ISteamVideo *GetISteamVideo(HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion)
    {
        STEAM_LOG(L"");
        return nullptr;
    }
};

struct CSteamUserStats : public ISteamUserStats
{
    SteamLeaderboard_t mLastLeaderboard = 0;

    virtual bool S_VIRTUAL RequestCurrentStats()
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual bool S_VIRTUAL GetStat(PCSTR name, int32 *data )
    {
        STEAM_LOG(L"");
        *data = 0;
        return true;
    };

    virtual bool S_VIRTUAL GetStat(PCSTR name, FLOAT *data)
    {
        STEAM_LOG(L"");
        *data = 0;
        return true;
    }

    virtual bool S_VIRTUAL SetStat(PCSTR name, int32 data)
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual bool S_VIRTUAL SetStat(PCSTR name, FLOAT data)
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual bool S_VIRTUAL UpdateAvgRateStat(PCSTR name, FLOAT countThisSession,  double sessionLength)
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual bool S_VIRTUAL GetAchievement(PCSTR name, bool *achieved)
    {
        STEAM_LOG(L"");
        *achieved = true;
        return true;
    }

    virtual bool S_VIRTUAL SetAchievement(PCSTR name)
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual bool S_VIRTUAL ClearAchievement(PCSTR name)
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual bool S_VIRTUAL GetAchievementAndUnlockTime(PCSTR name,
                              bool *achieved,
                              uint32 *unlockTime)
    {
        STEAM_LOG(L"");
        *achieved = true;
        *unlockTime = 0;
        return true;
    }

    virtual bool S_VIRTUAL StoreStats()
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual int S_VIRTUAL GetAchievementIcon(PCSTR name)
    {
        STEAM_LOG(L"");
        return 0;
    }

    virtual PCSTR S_VIRTUAL GetAchievementDisplayAttribute(PCSTR name, PCSTR key)
    {
        STEAM_LOG(L"");
        return "AchievementDisplayAttribute";
    }

    virtual bool S_VIRTUAL IndicateAchievementProgress(PCSTR name, uint32 curProgress, uint32 maxProgress)
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual uint32 S_VIRTUAL GetNumAchievements()
    {
        return 0;
    }

    virtual PCSTR S_VIRTUAL GetAchievementName( uint32 iAchievement )
    {
        return 0;
    }

    virtual SteamAPICall_t S_VIRTUAL RequestUserStats(CSteamID steamIDUser)
    {
        STEAM_LOG(L"");
        return k_uAPICallInvalid;
    }

    virtual bool S_VIRTUAL GetUserStat(CSteamID steamIDUser, PCSTR name, int32 *data)
    {
        STEAM_LOG(L"");
        *data = 0;
        return true;
    }

    virtual bool S_VIRTUAL GetUserStat(CSteamID steamIDUser, PCSTR name, FLOAT *data)
    {
        STEAM_LOG(L"");
        *data = 0;
        return true;
    }

    virtual bool S_VIRTUAL GetUserAchievement(CSteamID steamIDUser, PCSTR name, bool *achieved)
    {
        STEAM_LOG(L"");
        *achieved = true;
        return true;
    }

    virtual bool S_VIRTUAL GetUserAchievementAndUnlockTime(CSteamID steamIDUser, PCSTR name, bool *achieved, uint32 *unlockTime)
    {
        STEAM_LOG(L"");
        *achieved = true;
        *unlockTime = 0;
        return true;
    }

    virtual bool S_VIRTUAL ResetAllStats(bool achievementsToo)
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual SteamAPICall_t S_VIRTUAL FindOrCreateLeaderboard(
            PCSTR leaderboardName,
            ELeaderboardSortMethod leaderboardSortMethod,
            ELeaderboardDisplayType leaderboardDisplayType)
    {
        STEAM_LOG(L"");
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t S_VIRTUAL FindLeaderboard(PCSTR leaderboardName)
    {
        STEAM_LOG(L"");
        return k_uAPICallInvalid;
    }

    virtual PCSTR S_VIRTUAL GetLeaderboardName(SteamLeaderboard_t steamLeaderboard)
    {
        STEAM_LOG(L"");
        return "LeaderboardName";
    }

    virtual int S_VIRTUAL GetLeaderboardEntryCount(SteamLeaderboard_t steamLeaderboard)
    {
        STEAM_LOG(L"");
        mLastLeaderboard = steamLeaderboard;
        return 10;
    }

    virtual ELeaderboardSortMethod S_VIRTUAL GetLeaderboardSortMethod(SteamLeaderboard_t steamLeaderboard)
    {
        STEAM_LOG(L"");
        return k_ELeaderboardSortMethodDescending;
    }

    virtual ELeaderboardDisplayType S_VIRTUAL GetLeaderboardDisplayType(SteamLeaderboard_t steamLeaderboard)
    {
        STEAM_LOG(L"");
        return k_ELeaderboardDisplayTypeNumeric;
    }

    virtual SteamAPICall_t S_VIRTUAL DownloadLeaderboardEntries(SteamLeaderboard_t steamLeaderboard, ELeaderboardDataRequest leaderboardDataRequest, int rangeStart, int rangeEnd)
    {
        STEAM_LOG(L"");
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t S_VIRTUAL DownloadLeaderboardEntriesForUsers(SteamLeaderboard_t hSteamLeaderboard, CSteamID *prgUsers, int cUsers )
    {
        STEAM_LOG(L"");
        return k_uAPICallInvalid;
    }

    virtual bool S_VIRTUAL GetDownloadedLeaderboardEntry(
            SteamLeaderboardEntries_t steamLeaderboardEntries,
            int index,
            LeaderboardEntry_t *leaderboardEntry,
            int32 *details,
            int detailsMax)
    {
        STEAM_LOG(L"");
        *details = 0;
        return false;
    }

    virtual SteamAPICall_t S_VIRTUAL UploadLeaderboardScore(
            SteamLeaderboard_t steamLeaderboard,
            ELeaderboardUploadScoreMethod leaderboardUploadScoreMethod,
            int32 score,
            const int32 *scoreDetails,
            int scoreDetailsCount)
    {
        STEAM_LOG(L"");
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t S_VIRTUAL AttachLeaderboardUGC( SteamLeaderboard_t hSteamLeaderboard, ULONG64 hUGC )
    {
        STEAM_LOG(L"");
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t S_VIRTUAL GetNumberOfCurrentPlayers()
    {
        STEAM_LOG(L"");
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t S_VIRTUAL RequestGlobalAchievementPercentages()
    {
        STEAM_LOG(L"");
        return k_uAPICallInvalid;
    }

    virtual int S_VIRTUAL GetMostAchievedAchievementInfo( char *pchName, uint32 unNameBufLen, FLOAT *pflPercent, bool *pbAchieved )
    {
        STEAM_LOG(L"");
        *pflPercent = 100;
        *pbAchieved = true;
        return 0;
    }

    virtual int S_VIRTUAL GetNextMostAchievedAchievementInfo( int iIteratorPrevious, char *pchName, uint32 unNameBufLen, FLOAT *pflPercent, bool *pbAchieved )
    {
        STEAM_LOG(L"");
        ZeroMemory(pchName, unNameBufLen);
        *pflPercent = 100;
        *pbAchieved = true;
        return 0;
    }

    virtual bool S_VIRTUAL GetAchievementAchievedPercent( PCSTR pchName, FLOAT *pflPercent )
    {
        STEAM_LOG(L"");
        *pflPercent = 100;
        return false;
    }

    virtual SteamAPICall_t S_VIRTUAL RequestGlobalStats( int nHistoryDays )
    {
        STEAM_LOG(L"");
        return k_uAPICallInvalid;
    }

    virtual bool S_VIRTUAL GetGlobalStat( PCSTR pchStatName, int64 *pData )
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual bool S_VIRTUAL GetGlobalStat( PCSTR pchStatName, double *pData )
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual int32 S_VIRTUAL GetGlobalStatHistory( PCSTR pchStatName, int64 *pData, uint32 cubData )
    {
        STEAM_LOG(L"");
        return 0;
    }

    virtual int32 S_VIRTUAL GetGlobalStatHistory( PCSTR pchStatName, double *pData, uint32 cubData )
    {
        STEAM_LOG(L"");
        return 0;
    }
};

struct CSteamRemoteStorage : public ISteamRemoteStorage
{
    virtual bool S_VIRTUAL FileWrite(PCSTR FileName, const void* Data, int32 Size)
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual int32 S_VIRTUAL FileRead(PCSTR FileName, PVOID Data, int32 Size)
    {
        STEAM_LOG(L"");
        return 0;
    }

    virtual SteamAPICall_t FileWriteAsync(const char *pchFile, const void *pvData, uint32 cubData)
    {
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t FileReadAsync(const char *pchFile, uint32 nOffset, uint32 cubToRead)
    {
        return k_uAPICallInvalid;
    }

    virtual bool FileReadAsyncComplete(SteamAPICall_t hReadCall, void *pvBuffer, uint32 cubToRead)
    {
        return k_uAPICallInvalid;
    }

    virtual bool S_VIRTUAL FileForget(PCSTR FileName)
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual bool S_VIRTUAL FileDelete( PCSTR FileName )
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual SteamAPICall_t S_VIRTUAL FileShare( PCSTR FileName )
    {
        STEAM_LOG(L"");
        return k_uAPICallInvalid;
    }

    virtual bool S_VIRTUAL SetSyncPlatforms( PCSTR FileName, ERemoteStoragePlatform eRemoteStoragePlatform )
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual ULONG64 S_VIRTUAL FileWriteStreamOpen( PCSTR FileName )
    {
        STEAM_LOG(L"");
        return 0;
    }

    virtual bool S_VIRTUAL FileWriteStreamWriteChunk( ULONG64 writeHandle, const void *pvData, int32 cubData )
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual bool S_VIRTUAL FileWriteStreamClose( ULONG64 writeHandle )
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual bool S_VIRTUAL FileWriteStreamCancel( ULONG64 writeHandle )
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual bool S_VIRTUAL FileExists( PCSTR FileName )
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual bool S_VIRTUAL FilePersisted( PCSTR FileName )
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual int32 S_VIRTUAL GetFileSize( PCSTR FileName )
    {
        STEAM_LOG(L"");
        return 0;
    }

    virtual int64 S_VIRTUAL GetFileTimestamp( PCSTR FileName )
    {
        STEAM_LOG(L"");
        return 1;
    }

    virtual ERemoteStoragePlatform S_VIRTUAL GetSyncPlatforms( PCSTR FileName )
    {
        STEAM_LOG(L"");
        return k_ERemoteStoragePlatformWindows;
    }

    virtual int32 S_VIRTUAL GetFileCount()
    {
        STEAM_LOG(L"");
        return 0;
    }

    virtual PCSTR S_VIRTUAL GetFileNameAndSize( int iFile, int32 *pnFileSizeInBytes )
    {
        STEAM_LOG(L"");
        *pnFileSizeInBytes = 0;
        return "";
    }

    virtual bool S_VIRTUAL GetQuota(int32 *pnTotalBytes, int32 *puAvailableBytes )
    {
        STEAM_LOG(L"");
        *pnTotalBytes = 0x10000000;
        *puAvailableBytes = 0x10000000;
        return true;
    }

    virtual bool S_VIRTUAL IsCloudEnabledForAccount()
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual bool S_VIRTUAL IsCloudEnabledForApp()
    {
        STEAM_LOG(L"");
        return true;
    }

    virtual void S_VIRTUAL SetCloudEnabledForApp( bool bEnabled )
    {
        STEAM_LOG(L"");
    }

    virtual SteamAPICall_t S_VIRTUAL UGCDownload( ULONG64 hContent, uint32 unPriority )
    {
        STEAM_LOG(L"");
        return k_uAPICallInvalid;
    }

    virtual bool S_VIRTUAL GetUGCDownloadProgress( ULONG64 hContent, int32 *pnBytesDownloaded, int32 *pnBytesExpected )
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual bool S_VIRTUAL GetUGCDetails( ULONG64 hContent, AppId_t *pnAppID, char **ppchName, int32 *pnFileSizeInBytes, CSteamID *pSteamIDOwner )
    {
        STEAM_LOG(L"");
        return false;
    }

    virtual int32 S_VIRTUAL UGCRead(UGCHandle_t hContent, void *pvData, int32 cubDataToRead, uint32 cOffset, EUGCReadAction eAction )
    {
        STEAM_LOG(L"");
        return 0;
    }

    virtual int32 S_VIRTUAL GetCachedUGCCount()
    {
        STEAM_LOG(L"");
        return 0;
    }

    virtual ULONG64 S_VIRTUAL GetCachedUGCHandle( int32 iCachedContent )
    {
        STEAM_LOG(L"");
        return 0;
    }

#if defined(_PS3) || defined(_SERVER)
    virtual void GetFileListFromServer()
    {
    }

    virtual bool FileFetch(const char *pchFile)
    {
        return true;
    }

    virtual bool FilePersist(const char *pchFile)
    {
        return true;
    }

    virtual bool SynchronizeToClient()
    {
        return true;
    }

    virtual bool SynchronizeToServer()
    {
        return true;
    }

    virtual bool ResetFileRequestState()
    {
        return true;
    }

#endif

    // publishing UGC
    virtual SteamAPICall_t PublishWorkshopFile(const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags, EWorkshopFileType eWorkshopFileType)
    {
        return k_uAPICallInvalid;
    }

    virtual PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t unPublishedFileId)
    {
        return k_PublishedFileUpdateHandleInvalid;
    }

    virtual bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t updateHandle, const char *pchFile)
    {
        return true;
    }

    virtual bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t updateHandle, const char *pchPreviewFile)
    {
        return true;
    }

    virtual bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t updateHandle, const char *pchTitle)
    {
        return true;
    }

    virtual bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t updateHandle, const char *pchDescription)
    {
        return true;
    }

    virtual bool UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility)
    {
        return true;
    }

    virtual bool UpdatePublishedFileTags(PublishedFileUpdateHandle_t updateHandle, SteamParamStringArray_t *pTags)
    {
        return true;
    }

    virtual SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t updateHandle)
    {
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t unPublishedFileId, uint32 unMaxSecondsOld)
    {
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t DeletePublishedFile(PublishedFileId_t unPublishedFileId)
    {
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t EnumerateUserPublishedFiles(uint32 unStartIndex)
    {
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t SubscribePublishedFile(PublishedFileId_t unPublishedFileId)
    {
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t EnumerateUserSubscribedFiles(uint32 unStartIndex)
    {
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t unPublishedFileId)
    {
        return k_uAPICallInvalid;
    }

    virtual bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t updateHandle, const char *pchChangeDescription)
    {
        return true;
    }

    virtual SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t unPublishedFileId)
    {
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t unPublishedFileId, bool bVoteUp)
    {
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t unPublishedFileId)
    {
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t EnumerateUserSharedWorkshopFiles(CSteamID steamId, uint32 unStartIndex, SteamParamStringArray_t *pRequiredTags, SteamParamStringArray_t *pExcludedTags)
    {
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t PublishVideo(EWorkshopVideoProvider eVideoProvider, const char *pchVideoAccount, const char *pchVideoIdentifier, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags)
    {
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t SetUserPublishedFileAction(PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction)
    {
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t EnumeratePublishedFilesByUserAction(EWorkshopFileAction eAction, uint32 unStartIndex)
    {
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, uint32 unStartIndex, uint32 unCount, uint32 unDays, SteamParamStringArray_t *pTags, SteamParamStringArray_t *pUserTags)
    {
        return k_uAPICallInvalid;
    }

    virtual SteamAPICall_t UGCDownloadToLocation(UGCHandle_t hContent, const char *pchLocation, uint32 unPriority)
    {
        return k_uAPICallInvalid;
    }
};

class CSteamUtils : public ISteamUtils
{
public:
    virtual uint32 GetSecondsSinceAppActive()
    {
        return 0;
    }

    virtual uint32 GetSecondsSinceComputerActive()
    {
        return 0;
    }

    virtual EUniverse GetConnectedUniverse()
    {
        return k_EUniverseInvalid;
    }

    virtual uint32 GetServerRealTime()
    {
        return 0;
    }

    virtual const char *GetIPCountry()
    {
        return 0;
    }

    virtual bool GetImageSize( int iImage, uint32 *pnWidth, uint32 *pnHeight )
    {
        return false;
    }

    virtual bool GetImageRGBA( int iImage, uint8 *pubDest, int nDestBufferSize )
    {
        return false;
    }

    virtual bool GetCSERIPPort( uint32 *unIP, uint16 *usPort )
    {
        return false;
    }

    virtual uint8 GetCurrentBatteryPower()
    {
        return 0;
    }

    virtual uint32 GetAppID()
    {
        return 0;
    }

    virtual void SetOverlayNotificationPosition( ENotificationPosition eNotificationPosition )
    {
    }

    virtual bool IsAPICallCompleted( SteamAPICall_t hSteamAPICall, bool *pbFailed )
    {
        return true;
    }

    virtual ESteamAPICallFailure GetAPICallFailureReason( SteamAPICall_t hSteamAPICall )
    {
        return k_ESteamAPICallFailureNone;
    }

    virtual bool GetAPICallResult( SteamAPICall_t hSteamAPICall, void *pCallback, int cubCallback, int iCallbackExpected, bool *pbFailed )
    {
        return false;
    }

    virtual void RunFrame()
    {
    }

    virtual uint32 GetIPCCallCount()
    {
        return 0;
    }

    virtual void SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction )
    {
    }

    virtual bool IsOverlayEnabled()
    {
        return true;
    }

    //
    virtual bool BOverlayNeedsPresent()
    {
        return true;
    }

#ifndef _PS3
    virtual SteamAPICall_t CheckFileSignature( const char *szFileName )
    {
        return 0;
    }
#endif

#ifdef _PS3
    virtual void PostPS3SysutilCallback( uint64_t status, uint64_t param, void* userdata ) = 0;
    virtual bool BIsReadyToShutdown() = 0;
    virtual bool BIsPSNOnline() = 0;

    virtual void SetPSNGameBootInviteStrings( const char *pchSubject, const char *pchBody ) = 0;
#endif

    virtual bool ShowGamepadTextInput( EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char *pchDescription, uint32 unCharMax, const char *pchExistingText )
    {
        return true;
    }

    virtual uint32 GetEnteredGamepadTextLength()
    {
        return 0;
    }

    virtual bool GetEnteredGamepadTextInput( char *pchText, uint32 cchText )
    {
        return false;
    }

    virtual const char *GetSteamUILanguage()
    {
        return "chinese";
    }

    virtual bool IsSteamRunningInVR()
    {
        return false;
    }

    virtual void SetOverlayNotificationInset( int nHorizontalInset, int nVerticalInset )
    {
    }
};

class CSteamUser : public ISteamUser
{
public:
    virtual HSteamUser GetHSteamUser()
    {
        return 0;
    }

    virtual bool BLoggedOn()
    {
        return 0;
    }

    virtual CSteamID GetSteamID()
    {
        return CSteamID();
    }

    virtual int InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure )
    {
        return 0;
    }

    virtual void TerminateGameConnection( uint32 unIPServer, uint16 usPortServer )
    {
    }

    virtual void TrackAppUsageEvent( CGameID gameID, int eAppUsageEvent, const char *pchExtraInfo = "" )
    {
    }

    virtual bool GetUserDataFolder( char *pchBuffer, int cubBuffer )
    {
        return false;
    }

    virtual void StartVoiceRecording( )
    {
    }

    virtual void StopVoiceRecording( )
    {
    }

    virtual EVoiceResult GetAvailableVoice( uint32 *pcbCompressed, uint32 *pcbUncompressed, uint32 nUncompressedVoiceDesiredSampleRate )
    {
        return k_EVoiceResultNotInitialized;
    }

    virtual EVoiceResult GetVoice( bool bWantCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten, bool bWantUncompressed, void *pUncompressedDestBuffer, uint32 cbUncompressedDestBufferSize, uint32 *nUncompressBytesWritten, uint32 nUncompressedVoiceDesiredSampleRate )
    {
        return k_EVoiceResultNotInitialized;
    }

    virtual EVoiceResult DecompressVoice( const void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten, uint32 nDesiredSampleRate )
    {
        return k_EVoiceResultNotInitialized;
    }

    virtual uint32 GetVoiceOptimalSampleRate()
    {
        return 0;
    }

    virtual HAuthTicket GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket )
    {
        return 0;
    }

    virtual EBeginAuthSessionResult BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID )
    {
        return k_EBeginAuthSessionResultOK;
    }

    virtual void EndAuthSession( CSteamID steamID )
    {
    }

    virtual void CancelAuthTicket( HAuthTicket hAuthTicket )
    {
    }

    virtual EUserHasLicenseForAppResult UserHasLicenseForApp( CSteamID steamID, AppId_t appID )
    {
        return k_EUserHasLicenseResultHasLicense;
    }

    virtual bool BIsBehindNAT()
    {
        return true;
    }

    virtual void AdvertiseGame( CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer )
    {
    }

    virtual SteamAPICall_t RequestEncryptedAppTicket( void *pDataToInclude, int cbDataToInclude )
    {
        return 0;
    }

    virtual bool GetEncryptedAppTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket )
    {
        return false;
    }

    virtual int GetGameBadgeLevel( int nSeries, bool bFoil )
    {
        return 0;
    }

    virtual int GetPlayerSteamLevel()
    {
        return 0;
    }

    virtual SteamAPICall_t RequestStoreAuthURL( const char *pchRedirectURL )
    {
        return 0;
    }
};

class CSteamFriends : public ISteamFriends
{
public:
    virtual const char *GetPersonaName()
    {
        return "";
    }

    virtual SteamAPICall_t SetPersonaName( const char *pchPersonaName )
    {
        return 0;
    }

    virtual EPersonaState GetPersonaState()
    {
        return k_EPersonaStateOffline;
    }

    virtual int GetFriendCount( int iFriendFlags )
    {
        return 0;
    }

    virtual CSteamID GetFriendByIndex( int iFriend, int iFriendFlags )
    {
        return CSteamID();
    }

    virtual EFriendRelationship GetFriendRelationship( CSteamID steamIDFriend )
    {
        return k_EFriendRelationshipNone;
    }

    virtual EPersonaState GetFriendPersonaState( CSteamID steamIDFriend )
    {
        return k_EPersonaStateOffline;
    }

    virtual const char *GetFriendPersonaName( CSteamID steamIDFriend )
    {
        return "";
    }

    virtual bool GetFriendGamePlayed( CSteamID steamIDFriend, OUT_STRUCT() FriendGameInfo_t *pFriendGameInfo )
    {
        return false;
    }

    virtual const char *GetFriendPersonaNameHistory( CSteamID steamIDFriend, int iPersonaName )
    {
        return "";
    }

    virtual int GetFriendSteamLevel( CSteamID steamIDFriend )
    {
        return 0;
    }

    virtual const char *GetPlayerNickname( CSteamID steamIDPlayer )
    {
        return "";
    }

    virtual int GetFriendsGroupCount()
    {
        return 0;
    }

    virtual FriendsGroupID_t GetFriendsGroupIDByIndex( int iFG )
    {
        return 0;
    }

    virtual const char *GetFriendsGroupName( FriendsGroupID_t friendsGroupID )
    {
        return "";
    }

    virtual int GetFriendsGroupMembersCount( FriendsGroupID_t friendsGroupID )
    {
        return 0;
    }

    virtual void GetFriendsGroupMembersList( FriendsGroupID_t friendsGroupID, OUT_ARRAY_CALL(nMembersCount, GetFriendsGroupMembersCount, friendsGroupID ) CSteamID *pOutSteamIDMembers, int nMembersCount )
    {
    }

    virtual bool HasFriend( CSteamID steamIDFriend, int iFriendFlags )
    {
        return false;
    }

    virtual int GetClanCount()
    {
        return 0;
    }

    virtual CSteamID GetClanByIndex( int iClan )
    {
        return CSteamID();
    }

    virtual const char *GetClanName( CSteamID steamIDClan )
    {
        return "";
    }

    virtual const char *GetClanTag( CSteamID steamIDClan )
    {
        return "";
    }

    virtual bool GetClanActivityCounts( CSteamID steamIDClan, int *pnOnline, int *pnInGame, int *pnChatting )
    {
        return false;
    }

    virtual SteamAPICall_t DownloadClanActivityCounts( ARRAY_COUNT(cClansToRequest) CSteamID *psteamIDClans, int cClansToRequest )
    {
        return 0;
    }

    virtual int GetFriendCountFromSource( CSteamID steamIDSource )
    {
        return 0;
    }

    virtual CSteamID GetFriendFromSourceByIndex( CSteamID steamIDSource, int iFriend )
    {
        return CSteamID();
    }

    virtual bool IsUserInSource( CSteamID steamIDUser, CSteamID steamIDSource )
    {
        return false;
    }

    virtual void SetInGameVoiceSpeaking( CSteamID steamIDUser, bool bSpeaking )
    {
    }

    virtual void ActivateGameOverlay( const char *pchDialog )
    {
    }

    virtual void ActivateGameOverlayToUser( const char *pchDialog, CSteamID steamID )
    {
    }

    virtual void ActivateGameOverlayToWebPage( const char *pchURL )
    {
    }

    virtual void ActivateGameOverlayToStore( AppId_t nAppID, EOverlayToStoreFlag eFlag )
    {
    }

    virtual void SetPlayedWith( CSteamID steamIDUserPlayedWith )
    {
    }

    virtual void ActivateGameOverlayInviteDialog( CSteamID steamIDLobby )
    {
    }

    virtual int GetSmallFriendAvatar( CSteamID steamIDFriend )
    {
        return 0;
    }

    virtual int GetMediumFriendAvatar( CSteamID steamIDFriend )
    {
        return 0;
    }

    virtual int GetLargeFriendAvatar( CSteamID steamIDFriend )
    {
        return 0;
    }

    virtual bool RequestUserInformation( CSteamID steamIDUser, bool bRequireNameOnly )
    {
        return 0;
    }

    virtual SteamAPICall_t RequestClanOfficerList( CSteamID steamIDClan )
    {
        return 0;
    }

    virtual CSteamID GetClanOwner( CSteamID steamIDClan )
    {
        return CSteamID();
    }

    virtual int GetClanOfficerCount( CSteamID steamIDClan )
    {
        return 0;
    }

    virtual CSteamID GetClanOfficerByIndex( CSteamID steamIDClan, int iOfficer )
    {
        return CSteamID();
    }

    virtual uint32 GetUserRestrictions()
    {
        return 0;
    }

    virtual bool SetRichPresence( const char *pchKey, const char *pchValue )
    {
        return 0;
    }

    virtual void ClearRichPresence()
    {
    }

    virtual const char *GetFriendRichPresence( CSteamID steamIDFriend, const char *pchKey )
    {
        return "";
    }

    virtual int GetFriendRichPresenceKeyCount( CSteamID steamIDFriend )
    {
        return 0;
    }

    virtual const char *GetFriendRichPresenceKeyByIndex( CSteamID steamIDFriend, int iKey )
    {
        return "";
    }

    virtual void RequestFriendRichPresence( CSteamID steamIDFriend )
    {
    }

    virtual bool InviteUserToGame( CSteamID steamIDFriend, const char *pchConnectString )
    {
        return 0;
    }

    virtual int GetCoplayFriendCount()
    {
        return 0;
    }

    virtual CSteamID GetCoplayFriend( int iCoplayFriend )
    {
        return CSteamID();
    }

    virtual int GetFriendCoplayTime( CSteamID steamIDFriend )
    {
        return 0;
    }

    virtual AppId_t GetFriendCoplayGame( CSteamID steamIDFriend )
    {
        return 0;
    }

    virtual SteamAPICall_t JoinClanChatRoom( CSteamID steamIDClan )
    {
        return 0;
    }

    virtual bool LeaveClanChatRoom( CSteamID steamIDClan )
    {
        return 0;
    }

    virtual int GetClanChatMemberCount( CSteamID steamIDClan )
    {
        return 0;
    }

    virtual CSteamID GetChatMemberByIndex( CSteamID steamIDClan, int iUser )
    {
        return CSteamID();
    }

    virtual bool SendClanChatMessage( CSteamID steamIDClanChat, const char *pchText )
    {
        return 0;
    }

    virtual int GetClanChatMessage( CSteamID steamIDClanChat, int iMessage, void *prgchText, int cchTextMax, EChatEntryType *peChatEntryType, OUT_STRUCT() CSteamID *psteamidChatter )
    {
        return 0;
    }

    virtual bool IsClanChatAdmin( CSteamID steamIDClanChat, CSteamID steamIDUser )
    {
        return 0;
    }

    virtual bool IsClanChatWindowOpenInSteam( CSteamID steamIDClanChat )
    {
        return 0;
    }

    virtual bool OpenClanChatWindowInSteam( CSteamID steamIDClanChat )
    {
        return 0;
    }

    virtual bool CloseClanChatWindowInSteam( CSteamID steamIDClanChat )
    {
        return 0;
    }

    virtual bool SetListenForFriendsMessages( bool bInterceptEnabled )
    {
        return 0;
    }

    virtual bool ReplyToFriendMessage( CSteamID steamIDFriend, const char *pchMsgToSend )
    {
        return 0;
    }

    virtual int GetFriendMessage( CSteamID steamIDFriend, int iMessageID, void *pvData, int cubData, EChatEntryType *peChatEntryType )
    {
        return 0;
    }

    virtual SteamAPICall_t GetFollowerCount( CSteamID steamID )
    {
        return 0;
    }

    virtual SteamAPICall_t IsFollowing( CSteamID steamID )
    {
        return 0;
    }

    virtual SteamAPICall_t EnumerateFollowingList( uint32 unStartIndex )
    {
        return 0;
    }
};

//////////////////////////////////////////////////////////////////////////
// export
//////////////////////////////////////////////////////////////////////////

static CSteamApps           apps;
static CSteamUserStats      stat;
static CSteamClient         client;
static CSteamRemoteStorage  storage;
static CSteamUtils          utils;
static CSteamUser           user;
static CSteamFriends        friends;

bool S_CALLTYPE SteamAPI_Init()
{
    STEAM_LOG(L"");
    return true;
}

bool S_CALLTYPE SteamAPI_InitSafe()
{
    STEAM_LOG(L"");
    return false;
}

bool S_CALLTYPE SteamAPI_IsSteamRunning()
{
    STEAM_LOG(L"");
    return true;
}

void S_CALLTYPE SteamAPI_RegisterCallResult(struct CallbackBase *callback, SteamAPICall_t apiCall)
{
    STEAM_LOG(L"");
}

void S_CALLTYPE SteamAPI_RegisterCallback(struct CallbackBase *callback, int iCallback)
{
    STEAM_LOG(L"");
}

bool S_CALLTYPE SteamAPI_RestartAppIfNecessary(uint32 appId)
{
    STEAM_LOG(L"");
    return false;
}

void S_CALLTYPE SteamAPI_RunCallbacks()
{
    STEAM_LOG(L"");
}

void S_CALLTYPE SteamAPI_SetMiniDumpComment(PCSTR msg)
{
    STEAM_LOG(L"");
}

void S_CALLTYPE SteamAPI_Shutdown()
{
    STEAM_LOG(L"");
}

void S_CALLTYPE SteamAPI_UnregisterCallResult(struct CallbackBase *callback, SteamAPICall_t apiCall)
{
    STEAM_LOG(L"");
}

void S_CALLTYPE SteamAPI_UnregisterCallback(struct CallbackBase *callback)
{
    STEAM_LOG(L"");
}

void S_CALLTYPE SteamAPI_WriteMiniDump(uint32 exceptionCode, PVOID exceptionInfo, uint32 buildId)
{
    STEAM_LOG(L"");
}

ISteamApps* S_CALLTYPE SteamApps()
{
    STEAM_LOG(L"");
    return &apps;
}

ISteamUserStats* S_CALLTYPE SteamUserStats()
{
    STEAM_LOG(L"");
    return &stat;
}

ISteamClient* S_CALLTYPE SteamClient()
{
    STEAM_LOG(L"");
    return &client;
}

ISteamFriends* S_CALLTYPE SteamFriends()
{
    STEAM_LOG(L"");
    return &friends;
}

ISteamUtils* S_CALLTYPE SteamUtils()
{
    return &utils;
}

ISteamUser* S_CALLTYPE SteamUser()
{
    return &user;
}

ISteamGameServer* S_CALLTYPE SteamGameServer()
{
    STEAM_LOG(L"");
    DebugBreakPoint();
    return nullptr;
}

ISteamNetworking* S_CALLTYPE SteamGameServerNetworking()
{
    STEAM_LOG(L"");
    DebugBreakPoint();
    return nullptr;
}

ULONG64 S_CALLTYPE SteamGameServer_GetSteamID()
{
    STEAM_LOG(L"");
    return 251150;
}

bool S_CALLTYPE SteamGameServer_Init(uint32 ip, USHORT port, USHORT gamePort, USHORT spectatorPort, USHORT queryPort, EServerMode serverMode, PCSTR gameDir, PCSTR versionString)
{
    STEAM_LOG(L"");
    return true;
}

void S_CALLTYPE SteamGameServer_RunCallbacks()
{
    STEAM_LOG(L"");
}

void S_CALLTYPE SteamGameServer_Shutdown()
{
    STEAM_LOG(L"");
}

ISteamMatchmaking* S_CALLTYPE SteamMatchmaking()
{
    STEAM_LOG(L"");
    DebugBreakPoint();
    return nullptr;
}

ISteamMatchmakingServers* S_CALLTYPE SteamMatchmakingServers()
{
    STEAM_LOG(L"");
    DebugBreakPoint();
    return nullptr;
}

ISteamNetworking* S_CALLTYPE SteamNetworking()
{
    STEAM_LOG(L"");
    DebugBreakPoint();
    return nullptr;
}

ISteamRemoteStorage* S_CALLTYPE SteamRemoteStorage()
{
    STEAM_LOG(L"");
    return &storage;
}

ISteamScreenshots* S_CALLTYPE SteamScreenshots()
{
    STEAM_LOG(L"");
    return nullptr;
}
