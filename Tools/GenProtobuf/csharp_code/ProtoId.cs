// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ProtoId.proto
#pragma warning disable 1591, 0612, 3021
#region Designer generated code

using pb = global::Google.Protobuf;
using pbc = global::Google.Protobuf.Collections;
using pbr = global::Google.Protobuf.Reflection;
using scg = global::System.Collections.Generic;
namespace NetProto {

  /// <summary>Holder for reflection information generated from ProtoId.proto</summary>
  public static partial class ProtoIdReflection {

    #region Descriptor
    /// <summary>File descriptor for ProtoId.proto</summary>
    public static pbr::FileDescriptor Descriptor {
      get { return descriptor; }
    }
    private static pbr::FileDescriptor descriptor;

    static ProtoIdReflection() {
      byte[] descriptorData = global::System.Convert.FromBase64String(
          string.Concat(
            "Cg1Qcm90b0lkLnByb3RvEghOZXRQcm90byr+AwoHUHJvdG9JZBILCgdQSURf",
            "TWluEAASDAoIUElEX1BpbmcQARIMCghQSURfUG9uZxACEhUKEVBJRF9RdWVy",
            "eUZyZWVIZXJvEGQSEwoPUElEX1JzcEZyZWVIZXJvEGUSFQoRUElEX1NlbGVj",
            "dEhlcm9SZXEQZhIVChFQSURfU2VsZWN0SGVyb1JzcBBnEhkKFVBJRF9Mb2Fk",
            "U2NlbmVDb21wbGV0ZRBoEhIKDlBJRF9MZWF2ZVNjZW5lEGkSGAoUUElEX1B1",
            "bGxBbGxTY2VuZUluZm8QahIbChdQSURfUHVsbEFsbFNjZW5lSW5mb1JzcBBr",
            "EhkKFFBJRF9TY2VuZU9iamVjdFN0YXRlEOgHEh0KGFBJRF9TY2VuZU9iamVj",
            "dERpc2FwcGVhchDpBxIYChNQSURfTW92ZU9iamVjdFN0YXRlEPIHEh8KGlBJ",
            "RF9Nb3ZlT2JqZWN0TXV0YWJsZVN0YXRlEPMHEhIKDVBJRF9Nb3ZlVG9Qb3MQ",
            "/AcSEQoMUElEX1N0b3BNb3ZlEIYIEhcKElBJRF9CYXR0bGVPcGVyYVJlcRDM",
            "CBIVChBQSURfVmlld1NuYXBzaG90ENYIEhUKEFBJRF9WaWV3QWxsR3JpZHMQ",
            "1wgSGQoUUElEX1ZpZXdTbmFwc2hvdERpZmYQ2AgSDAoHUElEX01heBCAKEID",
            "+AEBYgZwcm90bzM="));
      descriptor = pbr::FileDescriptor.FromGeneratedCode(descriptorData,
          new pbr::FileDescriptor[] { },
          new pbr::GeneratedClrTypeInfo(new[] {typeof(global::NetProto.ProtoId), }, null));
    }
    #endregion

  }
  #region Enums
  public enum ProtoId {
    [pbr::OriginalName("PID_Min")] PidMin = 0,
    [pbr::OriginalName("PID_Ping")] PidPing = 1,
    [pbr::OriginalName("PID_Pong")] PidPong = 2,
    [pbr::OriginalName("PID_QueryFreeHero")] PidQueryFreeHero = 100,
    [pbr::OriginalName("PID_RspFreeHero")] PidRspFreeHero = 101,
    [pbr::OriginalName("PID_SelectHeroReq")] PidSelectHeroReq = 102,
    [pbr::OriginalName("PID_SelectHeroRsp")] PidSelectHeroRsp = 103,
    [pbr::OriginalName("PID_LoadSceneComplete")] PidLoadSceneComplete = 104,
    [pbr::OriginalName("PID_LeaveScene")] PidLeaveScene = 105,
    [pbr::OriginalName("PID_PullAllSceneInfo")] PidPullAllSceneInfo = 106,
    [pbr::OriginalName("PID_PullAllSceneInfoRsp")] PidPullAllSceneInfoRsp = 107,
    [pbr::OriginalName("PID_SceneObjectState")] PidSceneObjectState = 1000,
    [pbr::OriginalName("PID_SceneObjectDisappear")] PidSceneObjectDisappear = 1001,
    [pbr::OriginalName("PID_MoveObjectState")] PidMoveObjectState = 1010,
    [pbr::OriginalName("PID_MoveObjectMutableState")] PidMoveObjectMutableState = 1011,
    [pbr::OriginalName("PID_MoveToPos")] PidMoveToPos = 1020,
    [pbr::OriginalName("PID_StopMove")] PidStopMove = 1030,
    [pbr::OriginalName("PID_BattleOperaReq")] PidBattleOperaReq = 1100,
    [pbr::OriginalName("PID_ViewSnapshot")] PidViewSnapshot = 1110,
    [pbr::OriginalName("PID_ViewAllGrids")] PidViewAllGrids = 1111,
    [pbr::OriginalName("PID_ViewSnapshotDiff")] PidViewSnapshotDiff = 1112,
    [pbr::OriginalName("PID_Max")] PidMax = 5120,
  }

  #endregion

}

#endregion Designer generated code
